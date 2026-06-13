// hw1.c
// 用多线程计算一亿以内的质数
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 15
#define START 2
#define END 100000

int id = 1;
typedef struct Par
{
    int start;
    int end;
    int count;
} Par;

bool is_prime(int n)
{
    bool flag = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void *task1(void *arg)
{
    // 获得传入的参数
    Par *p = (Par *)arg;

    printf("线程（%d）%lu处理范围=%d-%d\n", id++, pthread_self(), p->start, p->end);

    for (int i = p->start; i <= p->end; i++)
    {
        if (is_prime(i))
        {
            // printf(" %d,", i);
            p->count++;
        }
    }
    printf("线程%lu处理完成=%d\n", pthread_self(), p->count);
    return NULL;
}

int main(int argc, char const *argv[])
{
    // 线程id
    pthread_t t[MAX];

    Par p[MAX];

    int size = END - START + 1; // 一亿
    int base_size = size / MAX; // 每个线程处理的范围

    for (int i = 0; i < MAX; i++)
    {
        p[i].start = i * base_size + START; // 每个线程处理的范围的起始值
        if (i == MAX - 1)
        {
            p[i].end = END;
        }
        else
        {
            p[i].end = p[i].start + base_size - 1;
        }

        p[i].count = 0;
    }

    for (int i = 0; i < MAX; i++)
    {
        // 线程的创建
        // printf("线程%d创建\n", i+1);
        pthread_create(&t[i], NULL, task1, &p[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        pthread_join(t[i], NULL);
    }
    int result = 0;
    for (int i = 0; i < MAX; i++)
    {
        printf("线程（%d）结果=%d\n", i + 1, p[i].count);
        result += p[i].count;
    }
    printf("结果：%d\n", result); // 5761455
    printf("main thread exit\n");
}
