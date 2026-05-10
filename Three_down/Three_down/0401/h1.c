#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
} Node;
typedef struct queue
{
    Node *head;
    Node *tail;
} Queue;

void init(Queue *q);
void show(Queue *q);
void enqueue(Queue *q, char val);
char dequeue(Queue *q);
bool empty(Queue *q);
int size(Queue *q);

int main(int argc, char const *argv[])
{
    Queue q;
    init(&q);
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');
    enqueue(&q, 'D');
    show(&q);

    dequeue(&q);
    show(&q);

    printf("%s\n", !empty(&q) ? "NOT NULL" : "NULL");
    printf("size=%d", size(&q));

    return 0;
}

void init(Queue *q)
{
    q->head = malloc(sizeof(Node));
    q->head->next = NULL;
    q->tail = q->head;
}
void show(Queue *q)
{
    Node *node = q->head->next;
    printf("{ ");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
    }
    printf("\b}\n");
    // printf("}");
}
void enqueue(Queue *q, char val)
{
    Node *node = malloc(sizeof(Node));
    node->data = val;
    q->tail->next = node;
    node->next = NULL;
    q->tail = node;
}
char dequeue(Queue *q)
{
    Node *node = q->head->next;
    if (q->tail == node)
    {
        free(q->tail);
        q->head->next = NULL;
        q->tail = q->head;
        return EXIT_SUCCESS;
    }
    Node *tmp = node->next;
    free(node);
    q->head->next = tmp;
}

bool empty(Queue *q)
{
    return q->tail == q->head;
}
int size(Queue *q)
{
    int index = 0;
    Node *node = q->head->next;
    while (node != NULL)
    {
        node = node->next;
        index++;
    }
    return index;
}
