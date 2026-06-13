// t2.c
// 线程的分离态
// 不可使用pthread_join()等待线程结束

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void *task(void *arg)
{
    int v = *((int *)arg);
    for (int i = 0; i <= v; i++)
    {
        printf("%lu:%d\n", pthread_self(), i);
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    // 线程编号
    pthread_t tid;

    // 线程属性

    // 分离态的子线程：后台执行，不返回数据，异步执行
    //  方案一
    //  创建之前使用pthread_attr_init初始化
    //  使用pthread_attr_setdetachstate设置分离态
    //  最后使用pthread_attr_destroy销毁
    pthread_attr_t *attr;
    pthread_attr_init(attr);
    pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);

    int v = 5;

    if (pthread_create(&tid, attr, task, &v) != 0)
    {
        perror("create error\n");
        return 1;
    }

    pthread_attr_destroy(attr);

    // pthread_exit(NULL);

    printf("main=%lu\n", pthread_self());
    sleep(1);
    // 方案二
    // pthread_create(&tid, NULL, task, NULL);
    // pthread_detach(tid);
    return 0;
}
