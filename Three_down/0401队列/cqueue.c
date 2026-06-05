// circle queue.c
// 循环队列
// 1.空一格
// 2.定义一个标识位

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 结构体
#define MAX 6

typedef struct queue
{
    char data[9];    // 数据
    int rear, front; // 队尾、队首
    int tag;         // 标识位
} Queue;

// 操作
void init(Queue *q);
bool enqueue(Queue *q, char val);
char dequeue(Queue *q);
bool full(Queue *q);
bool empty(Queue *q);
void show(Queue *q);
int size(Queue *q);

int main(int argc, char const *argv[])
{
    Queue q;
    init(&q);
    enqueue(&q, 'a');
    enqueue(&q, 'b');
    enqueue(&q, 'c');
    enqueue(&q, 'd');
    enqueue(&q, 'e');
    enqueue(&q, 'f');
    show(&q);

    printf("%c\n", dequeue(&q));
    printf("%c\n", dequeue(&q));
    // printf("%c\n", dequeue(&q));
    //   printf("%c\n", dequeue(&q));
    show(&q);

    enqueue(&q, 'g');
    enqueue(&q, 'h');
    printf("%s\n", !empty(&q) ? "NOT NULL" : "NULL");
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // enqueue(&q, 'A');
    // enqueue(&q, 'B');
    // enqueue(&q, 'C');
    // enqueue(&q, 'D');
    show(&q);
    return 0;
}
void init(Queue *q)
{
    q->front = q->rear = 0; // 空一格空间用于做判断
}
bool enqueue(Queue *q, char val)
{
    if (full(q))
        return false;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
}
char dequeue(Queue *q)
{

    if (!empty(q))
    {
        q->front = (q->front + 1) % MAX;
        char tmp = q->data[q->front];

        return tmp;
    }
    return EXIT_FAILURE;
}
bool full(Queue *q)
{

    return (q->rear + 1) % MAX == q->front;
}
bool empty(Queue *q)
{
    return q->front == q->rear;
}
void show(Queue *q)
{
    int t = 0;
    printf("{ ");
    // for (int i = (q->front + 1) % MAX; i != q->rear; (i + 1) % MAX)
    // {
    //     // i = i % MAX;
    //     // int index = (q->front + 1 + i) % MAX;
    //     // printf("t=%d\n", t);
    //     printf("%c,", q->data[i]);
    //     t++;
    // }
    for (int i = 0; i < size(q); i++)
    {
        // i = i % MAX;
        int index = (q->front + 1 + i) % MAX;
        // printf("t=%d\n", t);
        printf("%c,", q->data[index]);
        t++;
    }
    printf("\b}");
    printf("\n");
    // printf("t=%d\n", t);
}
int size(Queue *q)
{
    return (q->rear - q->front + MAX) % MAX;
}