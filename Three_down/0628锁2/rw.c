// rw.c

// 启用POSIX 2008 09

#define _POSIX_C_SOURCE 200809L

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_rwlock_t lock;
pthread_mutex_t mutex;
pthread_spinlock_t spin;

int n = 0;
void *rd(void *arg)
{
    while (1)
    {
        pthread_rwlock_rdlock(&lock);
        printf("%ld 读取：%d\n", pthread_self(), n);
        sleep(1);
        pthread_rwlock_unlock(&lock);
    }
    return NULL;
}
void *wr(void *arg)
{
    while (1)
    {
        pthread_rwlock_wrlock(&lock);
        n++;
        printf("====写线程，写入:%d\n", n);
        pthread_rwlock_unlock(&lock);
        sleep(3);
    }
    return NULL;
}

int main()
{

    pthread_rwlockattr_t attr;
    pthread_rwlockattr_init(&attr);
    pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);

    // 两个参数，第一个是读写锁，第二个是初始化参数，可用是NULL
    // 而用这个属性attr可用避免写线程进入饥饿状态
    pthread_rwlock_init(&lock, &attr);

    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, rd, NULL);
    pthread_create(&t2, NULL, rd, NULL);
    pthread_create(&t3, NULL, rd, NULL);
    pthread_create(&t4, NULL, wr, NULL);

    pthread_join(t4, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_rwlock_destroy(&lock);
    pthread_rwlockattr_destroy(&attr);
    return 0;
}