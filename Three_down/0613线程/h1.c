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
#include <dirent.h>
#include <iterator>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#define TASK_SIZE 1024

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
void init(Queue *q);
bool enqueue(Queue *q, char *val);
char dequeue(Queue *q);
bool full(Queue *q);
bool empty(Queue *q);

int main(int argc, char *argv[])
{
    pthread_mutex_init(&mylock, NULL);
    TaskArgs ta;
    AllCount ac;
    Queue q;
    ta.ac = &ac;
    ta.q = &q;

    init(&ta);

    getAllCount(&ta);

    // pthread_join(pthread_t th, void **thread_return)
    printf("文件数：%d\n", ta.ac->file_count);
    printf("目录数：%d\n", ta.ac->dir_count);
    printf("所有文件的总行数：%d\n", ta.ac->line_count);
    return 0;
}

// void *getAllCount(const char *dir_path, AllCount *ac)
// {
//     DIR *dir = opendir(dir_path);
//     if (dir == NULL)
//     {
//         perror("无法打开目录");
//         return;
//     }
//
//     struct dirent *entry;
//     while ((entry = readdir(dir)) != NULL)
//     {
//         // 跳过 . 和 ..
//         if (entry->d_name[0] == '.')
//         {
//             continue;
//         }
//
//         // 拼接完整路径
//         char full_path[1024];
//         snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
//
//         if (entry->d_type == DT_DIR)
//         {
//             ac->dir_count++;
//             getAllCount(full_path, ac); // 递归处理子目录
//         }
//         else if (entry->d_type == DT_REG)
//         {
//             ac->file_count++;
//             countLines(full_path, ac); // 统计文件行数
//         }
//     }
//     closedir(dir);
// }
void *Thread_getAllCount(void *arg)
{
    TaskArgs *ta = (TaskArgs *)arg;

    DIR *dir = opendir(ta->path);
    if (dir == NULL)
    {
        perror("无法打开目录");
        return NULL;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // 跳过 . 和 ..
        if (entry->d_name[0] == '.')
        {
            continue;
        }

        // 拼接完整路径
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR)
        {
            ta->ac->dir_count++;
            getAllCount(full_path, ta->ac); // 递归处理子目录
        }
        else if (entry->d_type == DT_REG)
        {
            ac->file_count++;
            countLines(full_path, ac); // 统计文件行数
        }
    }
    closedir(dir);
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
    for (int i = 0; i < 1024; i++)
    {
        ta->q->data[i] = malloc(sizeof(char *));
    }
}

bool enqueue(Queue *q, char *val)
{
    if (full(q))
        return false;
    q->rear = (q->rear + 1) % TASK_SIZE;
    q->data[q->rear] = val;
    return true;
}

bool dequeue(Queue *q)
{
    if (!empty(q))
    {
        q->front = (q->front + 1) % TASK_SIZE;
        q->data[q->front] = 0;
        return true;
    }
    return false;
}

bool full(Queue *q)
{

    return (q->rear + 1) % MAX == q->front;
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
    ac->line_count += line_count;
    fclose(fp);
}

// 多线程统计行数
void *Thread_countLines(void *arg)
{
    TaskArgs *ta = (TaskArgs *)arg;
    FILE *fp = fopen(ta->path, "r");
    if (!fp)
    {
        perror("文件无法打开");
        return NULL;
    }

    char buf[1024];
    int line_count = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        line_count++;
    }
    ta->ac->line_count += line_count;

    fclose(fp);

    return NULL;
}
