// hw1.c
// 使用线程和信号量实现停车场问题

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// 定义停车场容量
#define MAX_SPACE 20

// 定义全局变量锁和条件变量
sem_t sem_mutex;
sem_t sem_space;
sem_t sem_car;

// 初始车的数量
int car = 0;

void *car_enter(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 10; i++)
    {
        int val;
        sem_getvalue(&sem_space, &val);
        if (val == 0)
        {
            printf("\t====车位已满，%d号入口禁止进入====\n", id);
        }
        sem_wait(&sem_space);
        sem_wait(&sem_mutex);
        car++;
        printf("%d号入口有车辆进入，当前车数为：%d \n", id, car);
        sem_post(&sem_mutex);
        sem_post(&sem_car);

        // sleep(rand() % 3 + 1);
    }
    return NULL;
}
void *car_leave(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 15; i++)
    {
        int val;
        sem_getvalue(&sem_car, &val);
        if (val == 0)
        {
            printf("\t====车位已空，等待车辆进入====\n");
        }
        sem_wait(&sem_car);
        sem_wait(&sem_mutex);
        car--;
        printf("\t\t\t\t\t%d号出口有车辆离开，当前车数为：%d \n", id, car);
        sem_post(&sem_mutex);
        sem_post(&sem_space);
        // sleep(1);
        // sleep(rand() % 3 + 1);
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    // 三个入口和出口
    pthread_t e1, e2, e3, l1, l2, l3;

    sem_init(&sem_space, 0, MAX_SPACE);
    sem_init(&sem_car, 0, 0);
    sem_init(&sem_mutex, 0, 1);

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

    sem_destroy(&sem_mutex);
    sem_destroy(&sem_space);
    sem_destroy(&sem_car);

    return 0;
}