// t.c
//  线程的创建与执行
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *task(void *)
{
    printf("子线程执行\n");
    for (int i = 1; i < 10; i++)
    {
        printf("kid%d\n", i);
        sleep(1);
    }

    return NULL;
}

int main(int argc, char const *argv[])
{
    // 线程id
    pthread_t tid;
    // 线程的创建
    //  参数：
    //  1 pthread_t 线程id
    //  2 pthread_attr_t 线程属性
    //  3 void* (*void*) 线程函数的指针
    //  4 void* 线程函数的参数指针
    // 线程属性：默认值为NULL
    int r = pthread_create(&tid, NULL, task, NULL);

    // 参数：
    //   1 pthread_t 线程id
    //   2 void** 线程函数的返回值指针
    pthread_join(tid, NULL);
    printf("是否创建成功=%d\n", r);
    printf("线程id=%ld\n", tid);
    for (int i = 1; i < 10; i++)
    {
        printf("main%d\n", i);
        sleep(1);
    }
    printf("main thread exit\n");

    return 0;
}