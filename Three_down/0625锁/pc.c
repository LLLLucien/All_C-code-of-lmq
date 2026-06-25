// pc.c
// 生成者消费者模型

#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// 队列容量
#define MAX 5

// 互斥锁
pthread_mutex_t mutex;

// 条件变量
pthread_cond_t cond_full;  // 满
pthread_cond_t cond_empty; // 空

int n = 0;
int p = 1;
int c = 1;
// 生产者线程函数
void *producer(void *arg)
{
    pthread_t tid = pthread_self();
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        while (n >= MAX)
        {
            printf("\t\t生成者：队列已满，阻塞\n");
            // 进入等待（阻塞）状态
            pthread_cond_wait(&cond_empty, &mutex);
        }

        n++;
        printf("%lu号生产者：生产了%d,第%d生产\n", tid, n, p);
        p++;
        // 唤醒一个因为cond_full而等待的线程
        pthread_cond_signal(&cond_full);

        // 唤醒所有因为cond_full而等待的线程
        // pthread_cond_broadcast(&cond_full);

        pthread_mutex_unlock(&mutex);
        // sleep(1);

        // 主动让出处理器时间，从运行状态进入就绪状态
        sched_yield();
    }
    return NULL;
}
// 消费者线程函数
void *consumer(void *arg)
{
    for (int i = 0; i < 20; i++)
    {
        pthread_mutex_lock(&mutex);
        while (n <= 0)
        {
            printf("\t\t消费者：队列为空，阻塞\n");
            // 进入等待（阻塞）状态，等待收到信号
            pthread_cond_wait(&cond_full, &mutex);
        }
        n--;
        printf("\t\t\t\t消费者：消费了%d,第%d次消费\n", n, c);
        c++;
        // 唤醒一个因为cond_empty而等待的线程
        pthread_cond_signal(&cond_empty);

        // pthread_cond_broadcast(&cond_empty);唤醒所有

        pthread_mutex_unlock(&mutex);
        // sleep(2);
        sched_yield();
    }

    return NULL;
}

int main()
{
    pthread_t t1; // 生产者线程
    pthread_t t2; // 消费者线程
    pthread_t t3; // 生成者线程

    pthread_mutex_init(&mutex, NULL); // 初始化互斥锁

    pthread_cond_init(&cond_full, NULL); // 初始化条件变量
    pthread_cond_init(&cond_empty, NULL);

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_create(&t3, NULL, producer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&mutex); // 销毁锁

    pthread_cond_destroy(&cond_full); // 销毁条件变量
    pthread_cond_destroy(&cond_empty);
    return 0;
}