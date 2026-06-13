// t1.c
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Par
{
    int start;
    int end;
    int count;
}Par;

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

    for (int i = p->start; i <= p->end; i++)
    {
        if (is_prime(i))
        {
            printf(" %d,", i);
            p->count++;
        }
    }
    printf("\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    // 线程id
    pthread_t t1;


    Par *p = malloc(sizeof(Par));
    p->start = 2;
    p->end = 100;
    p->count = 0;
    // 线程的创建
    pthread_create(&t1, NULL, task1, p);

    pthread_join(t1, NULL);
    int result = p->count;
    printf("结果：%d\n", result);
    printf("main thread exit\n");
}
