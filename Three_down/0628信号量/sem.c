// sem.c
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 线程最大数量
#define MAX 8
// 可用线程数量
#define N 5

sem_t sem;

void *task(void *p)
{
    int id = *(int *)p;
    free(p);

    sem_wait(&sem);
    printf("线程%d启动\n", id);
    sleep(3);
    printf("\t\t线程%d结束---\n", id);
    sem_post(&sem);

    return NULL;
}

int main()
{
    sem_init(&sem, 0, N);
    pthread_t tid[MAX];

    for (int i = 0; i < MAX; i++)
    {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&tid[i], NULL, task, (void *)id);
    }

    for (int i = 0; i < MAX; i++)
    {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}