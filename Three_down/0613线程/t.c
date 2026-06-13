// t.c
// 线程的非分离态

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void *task(void *arg)
{
    pthread_t tid = pthread_self();

    printf("sub=%lu\n", tid);

    // 由于task是void*类型，所以返回值需要动态分配内存
    int *val = malloc(sizeof(int));
    *val = 5;
    pthread_exit((void *)val);
    return (void *)5;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    if (pthread_create(&tid, NULL, task, NULL) != 0)
    {
        perror("create error\n");
        return 1;
    }

    printf("main=%lu\n", pthread_self());
    void *val;
    pthread_join(tid, &val);
    int v = *((int *)val);
    printf("v=%d\n", v);
    free(val);
    return 0;
}