// 使用多线程统计文件总行数，并写入文件

/* 清除缓存
sync && echo 3 | sudo tee /proc/sys/vm/drop_caches


*/

#include <dirent.h>
#include <pthread.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/types.h>
#include <time.h>
#include <unistd.h>
#define TASK_SIZE 102400
#define TID_MAX 10
typedef struct AllCount
{
    int file_count; // 文件数
    int dir_count;  // 目录数
    int line_count; // 所有文件的总行数
} AllCount;

// 任务循环队列
typedef struct queue
{
    char *data[TASK_SIZE];    // 数量
    int rear, front;          // 队尾、队首
    pthread_mutex_t lock;     // 保护队列的锁
    pthread_cond_t not_empty; // 队列非空条件变量
    pthread_cond_t not_full;  // 队列非满条件变量
} Queue;

// 传给统计行数的函数的参数
typedef struct
{
    char *path;   //   路径
    AllCount *ac; // 各类统计的结构体
    Queue *q;
    int done; // 队列为空而且查完所有文件和目录的标注位
} TaskArgs;

pthread_mutex_t countLock; // 保护 line_count 的锁

void init(TaskArgs *ta);

// 循环队列的函数声明
bool enqueue(Queue *q, char *val);
char *dequeue(Queue *q);
bool full(Queue *q);
bool empty(Queue *q);

void *Thread_SCAN_ALL_FILE(void *arg); // 一个线程用于调用分辨文件和目录的函数
void getAllCount(const char *dir_path, AllCount *ac, Queue *q); // 分辨文件和目录的函数

void *Thread_countLines(void *arg);        // 一个线程用于调用统计文件总行数的函数
void countLines(char *path, AllCount *ac); // 统计文件总行数

// 把结果输入到文件里
void Output_Result(AllCount *ac, double elapsed);

int main(int argc, char *argv[])
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); // 开始计时

    pthread_mutex_init(&countLock, NULL);

    TaskArgs *ta = malloc(sizeof(TaskArgs));
    AllCount *ac = malloc(sizeof(AllCount));
    Queue *q = malloc(sizeof(Queue));
    ta->ac = ac;
    ta->q = q;

    init(ta);

    pthread_t tid[TID_MAX];
    // 第一个默认是进行判断文件类型的线程
    // 所以至少需要两个线程才能成功运行此程序
    pthread_create(&tid[0], NULL, Thread_SCAN_ALL_FILE, (void *)ta);

    for (int i = 1; i < TID_MAX; i++)
    {
        pthread_create(&tid[i], NULL, Thread_countLines, (void *)ta);
    }
    for (int i = 0; i < TID_MAX; i++)
    {
        pthread_join(tid[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end); // 结束计时
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("文件数：%d\n", ta->ac->file_count);
    printf("目录数：%d\n", ta->ac->dir_count);
    printf("所有文件的总行数：%d\n", ta->ac->line_count);
    printf("耗时：%.3f 秒\n", elapsed);

    Output_Result(ta->ac, elapsed);

    // 销毁队列的锁和条件变量
    pthread_mutex_destroy(&q->lock);
    pthread_cond_destroy(&q->not_empty);
    pthread_cond_destroy(&q->not_full);

    free(ta);
    free(ac);
    free(q);
    pthread_mutex_destroy(&countLock);

    return 0;
}

void getAllCount(const char *dir_path, AllCount *ac, Queue *q)
{
    DIR *dir = opendir(dir_path);
    if (dir == NULL)
    {
        perror("无法打开目录");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // 跳过 . 和 ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        // 拼接完整路径
        int len = strlen(dir_path) + strlen(entry->d_name) + 2; // +2: / 和 \0

        char *full_path = malloc(len);

        snprintf(full_path, len, "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR)
        {
            ac->dir_count++;
            getAllCount(full_path, ac, q); // 递归处理子目录
        }
        else if (entry->d_type == DT_REG)
        {

            ac->file_count++;
            enqueue(q, full_path); // 把文件路径加入任务队列
        }
        free(full_path);
    }
    closedir(dir);
}
void *Thread_SCAN_ALL_FILE(void *arg)
{
    // 以后传入的参数可能不会硬性规定哪个，可能是任意目录，但不可能是文件，所以无需判断类型
    TaskArgs *ta = (TaskArgs *)arg;

    DIR *dir = opendir(ta->path);
    if (dir == NULL)
    {
        perror("无法打开目录");

        return NULL;
    }
    // getAllCount 内部会自己 opendir，这里只是验证能否打开
    closedir(dir);

    ta->ac->dir_count++;
    getAllCount(ta->path, ta->ac, ta->q); // 递归处理子目录

    // 到这里说明扫描完了
    if (ta->done == 0)
        ta->done = 1;

    // 扫描完成后，放入 TID_MAX-1 个结束标记，通知所有消费线程退出
    for (int i = 1; i < TID_MAX; i++)
    {
        enqueue(ta->q, "__END__");
    }

    return NULL;
}

void init(TaskArgs *ta)
{
    ta->done = 0;
    ta->ac->file_count = 0;
    ta->ac->dir_count = 0;
    ta->ac->line_count = 0;
    // 硬性规定了路径
    ta->path = "/home/lmq20233547/linux-7.0.10";
    // 初始化任务队列
    ta->q->rear = ta->q->front = 0;
    // 初始化队列的锁和条件变量
    pthread_mutex_init(&ta->q->lock, NULL);
    pthread_cond_init(&ta->q->not_empty, NULL);
    pthread_cond_init(&ta->q->not_full, NULL);
}

bool enqueue(Queue *q, char *val)
{

    pthread_mutex_lock(&q->lock);
    // 队列满就休眠等待，直到有消费者取走数据后唤醒
    while (full(q))
        pthread_cond_wait(&q->not_full, &q->lock);

    q->rear = (q->rear + 1) % TASK_SIZE;
    q->data[q->rear] = strdup(val); // strdup = malloc + strcpy，复制一份

    pthread_mutex_unlock(&q->lock);
    // 放入数据后，通知等待的消费者"队列非空了"
    pthread_cond_signal(&q->not_empty);
    return true;
}

/*
 * dequeue：消费者取出任务
 */
char *dequeue(Queue *q)
{
    pthread_mutex_lock(&q->lock);

    // 队列空就休眠等待，直到有生产者放入数据后唤醒
    while (empty(q))
        pthread_cond_wait(&q->not_empty, &q->lock);

    q->front = (q->front + 1) % TASK_SIZE;
    char *val = q->data[q->front];

    // 取出数据后，通知等待的生产者"队列非满了"
    pthread_cond_signal(&q->not_full);
    pthread_mutex_unlock(&q->lock);
    return val;
}

bool full(Queue *q)
{

    return (q->rear + 1) % TASK_SIZE == q->front;
}
bool empty(Queue *q)
{
    return q->front == q->rear;
}

// 统计文件行数
void countLines(char *path, AllCount *ac)
{
    FILE *fp = fopen(path, "r");
    if (!fp)
    {
        perror("文件无法打开");
        return;
    }

    char buf[1024];
    int line_count = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        line_count++;
    }
    pthread_mutex_lock(&countLock);
    ac->line_count += line_count;
    pthread_mutex_unlock(&countLock);
    fclose(fp);
}

/*
 * 多线程统计行数
 * 收到 "__END__" 后退出
 */
void *Thread_countLines(void *arg)
{
    TaskArgs *ta = (TaskArgs *)arg;
    // 读取循环队列的队首
    while (1)
    {
        char *tmp_path = dequeue(ta->q);

        // 收到结束标记，退出
        if (strcmp(tmp_path, "__END__") == 0)
        {
            free(tmp_path);
            break;
        }

        countLines(tmp_path, ta->ac);
        free(tmp_path);
    }
    return NULL;
}

void Output_Result(AllCount *ac, double elapsed)
{
    FILE *fp = fopen("result.txt", "a");
    if (!fp)
    {
        perror("文件无法打开");
        return;
    }
    fprintf(fp, "------------------------\n");
    fprintf(fp, "线程数：%d\n", TID_MAX);
    fprintf(fp, "文件数：%d\n", ac->file_count);
    fprintf(fp, "目录数：%d\n", ac->dir_count);
    fprintf(fp, "所有文件的总行数：%d\n", ac->line_count);
    fprintf(fp, "耗时：%.3f 秒\n", elapsed);
    fprintf(fp, "------------------------\n");
    printf("输出结果已经存入 result.txt 完成\n");
    fclose(fp);
}