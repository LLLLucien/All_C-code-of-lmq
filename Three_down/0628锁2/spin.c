// spin.c

// 启用POSIX 2008 09

#define _POSIX_C_SOURCE 200809L

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 自旋锁
pthread_spinlock_t spin;
pthread_mutex_t mutex;

int n = 0;
// 没有锁：4-6
// 互斥锁：80-100
// 自旋锁：50-100
void *task(void *arg)
{
    // 局部变量
    // 避免被编译器优化：写入寄存器，直接从寄存器读取
    // volatile 只防止编译器优化，不保证原子性，也不替代锁。
    // 它适合配合锁/自旋锁使用，确保拿到锁之后读到的是最新值。
    volatile int t = n;
    for (int i = 0; i < 1000000; i++)
    {
        t++;
    }
    // pthread_mutex_lock(&mutex);
    pthread_spin_lock(&spin);
    n += t;
    pthread_spin_unlock(&spin);
    return NULL;
    // pthread_mutex_unlock(&mutex);
}

int main()
{
    // 0表示在一个进程间，1表示在多个进程间
    pthread_spin_init(&spin, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);
    pthread_create(&t3, NULL, task, NULL);
    pthread_create(&t4, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_spin_destroy(&spin);

    printf("n = %d\n", n);
    return 0;
}