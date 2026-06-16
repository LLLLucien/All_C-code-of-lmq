// 使用多线程统计文件总行数
// 发现需要加上锁
/*
pthread_mutex_t mylock;
int main()
{
    pthread_mutex_init(&mylock, NULL);  // 第二个参数是属性，NULL表示默认
    // ...
}


// 加锁
pthread_mutex_lock(&mylock);
total_lines += lines;
// 解锁
pthread_mutex_unlock(&mylock);

//确保没有线程使用锁再销毁

pthread_mutex_destroy(&mylock);
*/
// 32-  8.32
// 16-  7.13
// 10-  6.9
// 8-   6.98
// 5-   7.69
// 4-   8.83
// 3-   9.97
// 2-   15.64
/* 清除缓存
sync && echo 3 | sudo tee /proc/sys/vm/drop_caches

跳过了一些带.的文件结果
文件数：92492
目录数：6108
所有文件的总行数：42267256

只跳过.和..的结果
文件数：92939
目录数：6108
所有文件的总行数：42272781
 */
#include <dirent.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#define TASK_SIZE 1024
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
    char *data[TASK_SIZE]; // 数量
    int rear, front;       // 队尾、队首

} Queue;

// 传给统计行数的函数的参数
typedef struct
{
    char *path;   //   路径
    AllCount *ac; // 各类统计的结构体
    Queue *q;
    int done; // 队列为空而且查完所有文件和目录的标注位
} TaskArgs;

pthread_mutex_t mylock; // 全局锁
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

int main(int argc, char *argv[])
{
    pthread_mutex_init(&mylock, NULL);
    TaskArgs *ta = malloc(sizeof(TaskArgs));
    AllCount *ac = malloc(sizeof(AllCount));
    Queue *q = malloc(sizeof(Queue));
    ta->ac = ac;
    ta->q = q;

    init(ta);

    pthread_t tid[TID_MAX];
    // 第一个默认是进行判断文件类型的线程
    pthread_create(&tid[0], NULL, Thread_SCAN_ALL_FILE, (void *)ta);

    for (int i = 1; i < TID_MAX; i++)
    {
        pthread_create(&tid[i], NULL, Thread_countLines, (void *)ta);
    }
    for (int i = 0; i < TID_MAX; i++)
    {
        pthread_join(tid[i], NULL);
    }

    printf("文件数：%d\n", ta->ac->file_count);
    printf("目录数：%d\n", ta->ac->dir_count);
    printf("所有文件的总行数：%d\n", ta->ac->line_count);

    free(ta);
    free(ac);
    free(q);
    pthread_mutex_destroy(&mylock);
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
        // if (entry->d_name[0] == '.')
        // {
        //     continue;
        // }
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
    // 以后传入的参数可能不会硬性规定哪个，可能是任意目录，但不可能是文件
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
}

bool enqueue(Queue *q, char *val)
{
    // 如果满了，就一直等，直到有空位
    // 前提是线程一定会一直取任务
    while (1)
    {
        pthread_mutex_lock(&mylock);
        if (!full(q))
        {
            q->rear = (q->rear + 1) % TASK_SIZE;
            q->data[q->rear] = strdup(val); // strdup = malloc + strcpy，复制一份
            pthread_mutex_unlock(&mylock);
            return true;
        }
        pthread_mutex_unlock(&mylock);
    }
}

char *dequeue(Queue *q)
{
    if (!empty(q))
    {
        q->front = (q->front + 1) % TASK_SIZE;

        return q->data[q->front];
    }
    return NULL;
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
    pthread_mutex_lock(&mylock);
    ac->line_count += line_count;
    pthread_mutex_unlock(&mylock);
    fclose(fp);
}

// 多线程统计行数
void *Thread_countLines(void *arg)
{
    TaskArgs *ta = (TaskArgs *)arg;
    // 读取循环队列的队首
    while (1)
    {
        pthread_mutex_lock(&mylock);
        if (empty(ta->q) && ta->done == 1)
        {
            pthread_mutex_unlock(&mylock);
            break;
        }
        char *tmp_path = dequeue(ta->q);
        pthread_mutex_unlock(&mylock);

        if (tmp_path == NULL)
        {
            continue; // 队列暂时为空，继续循环等待
        }

        countLines(tmp_path, ta->ac);
        free(tmp_path);
    }
    return NULL;
}