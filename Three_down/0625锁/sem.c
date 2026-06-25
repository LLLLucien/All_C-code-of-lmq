// sem.c
//  信号量
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 信号量
sem_t sem;

int n = 0;

void *task(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        // 信号值-1
        sem_wait(&sem);
        n++;
        // 信号值+1
        sem_post(&sem);
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    // 初始化信号量
    // 参数：
    // 1.信号量本身地址，
    // 2.是否是线程间还是进程间，0表示线程间（一个进程内），1表示进程间
    // 3.初始值:1 二元信号量；其他值称为计数器信号量
    sem_init(&sem, 0, 1);

    // 相对于可以同时跑9个
    // sem_init(&sem_sum, 0, 9);

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("n=%d\n", n);

    sem_destroy(&sem);
    return 0;
}