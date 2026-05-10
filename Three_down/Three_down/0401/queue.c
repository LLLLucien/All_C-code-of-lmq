// queue.c
// 队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 结构体
#define MAX 10

typedef struct queue
{
    char data[9];    // 数据
    int rear, front; // 队尾、队首
} Queue;

// 操作
void init(Queue *q);
void enqueue(Queue *q, char val);
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
    show(&q);
    printf("%c\n", dequeue(&q));
    printf("%c\n", dequeue(&q));
    printf("%c\n", dequeue(&q));
    //  printf("%c\n", dequeue(&q));
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
    q->front = q->rear = -1;
}
void enqueue(Queue *q, char val)
{
    if (full(q))
        return;
    q->data[++q->rear] = val;
}
char dequeue(Queue *q)
{

    if (!empty(q))
    {
        char tmp = q->data[++q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        return tmp;
    }
    return EXIT_FAILURE;
}
bool full(Queue *q)
{
    return q->rear == MAX - 1;
}
bool empty(Queue *q)
{
    return q->front == q->rear;
}
void show(Queue *q)
{

    printf("{ ");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%c,", q->data[i]);
    }
    printf("\b}");
    printf("\n");
}
int size(Queue *q)
{
    return q->rear - q->front;
}