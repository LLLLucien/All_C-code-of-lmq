// hw1.c
// 使用线程和条件变量实现停车场问题

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// 定义停车场容量
#define MAX_SPACE 50

// 定义全局变量锁和条件变量
pthread_mutex_t mutex;
pthread_cond_t cond_empty;
pthread_cond_t cond_full;

// 初始车的数量
int car = 0;

void *car_enter(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 50; i++)
    {
        pthread_mutex_lock(&mutex);
        while (car >= MAX_SPACE)
        {
            printf("\t====车位已满,%d号入口禁止进入====\n", id);
            pthread_cond_wait(&cond_empty, &mutex);
        }
        car++;
        printf("%d号入口有车辆进入，当前车数为：%d \n", id, car);
        pthread_cond_signal(&cond_full);
        pthread_mutex_unlock(&mutex);
        // sleep(rand() % 3 + 1);
    }
    return NULL;
}
void *car_leave(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 75; i++)
    {
        pthread_mutex_lock(&mutex);
        while (car <= 0)
        {
            printf("\t====车位已空，等待车辆进入====\n");
            pthread_cond_wait(&cond_full, &mutex);
        }
        car--;
        printf("\t\t\t\t\t%d号出口有车辆离开，当前车数为：%d \n", id, car);
        pthread_cond_signal(&cond_empty);
        pthread_mutex_unlock(&mutex);
        // sleep(rand() % 3 + 1);
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    // 三个入口和出口
    pthread_t e1, e2, e3, l1, l2, l3;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_empty, NULL);
    pthread_cond_init(&cond_full, NULL);

    // 给每个线程分配一个编号，通过 arg 传入
    int id_e1 = 1, id_e2 = 2, id_e3 = 3;
    int id_l1 = 1, id_l2 = 2, id_l3 = 3;

    pthread_create(&e1, NULL, car_enter, &id_e1);
    pthread_create(&e2, NULL, car_enter, &id_e2);
    pthread_create(&e3, NULL, car_enter, &id_e3);

    pthread_create(&l1, NULL, car_leave, &id_l1);
    pthread_create(&l2, NULL, car_leave, &id_l2);
    // pthread_create(&l3, NULL, car_leave, &id_l3);

    pthread_join(e1, NULL);
    pthread_join(e2, NULL);
    pthread_join(e3, NULL);
    pthread_join(l1, NULL);
    pthread_join(l2, NULL);
    // pthread_join(l3, NULL);

    return 0;
}