// 链表栈
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    char data;
    struct stack *next;
} Stack, Node;

void init(Stack *s);
void push(Stack *s, char data);
Node *pop(Stack *s);
Node *top(Stack *s);
void clean(Stack *s);
bool empty(Stack *s);

int main(int argc, char const *argv[])
{
    Stack s;
    init(&s);
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        push(&s, a[i]);
    }
    // push(&s, 'a');
    // push(&s, 'b');
    // push(&s, 'c');
    // push(&s, 'd');
    while (!empty(&s))
    {
        Node *p = pop(&s);
        printf("%c,", p->data);
        free(p);
    }
    printf("\b ");
    printf("\n");

    printf("%s\n", !empty(&s) ? "NOT NULL" : "NULL");

    return 0;
}
void init(Stack *s)
{
    s->next = NULL;
}
void push(Stack *s, char data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = s->next;
    s->next = node;
}
Node *pop(Stack *s)
{
    if (s->next == NULL)
    {
        return NULL;
    }
    Node *node = s->next;

    s->next = node->next;

    return node;
}
Node *top(Stack *s)
{
    Node *node = s->next;
    return node;
}
void clean(Stack *s)
{
    Node *node = s->next;
    while (node != NULL)
    {
        Node *tmp = node->next;
        free(node);
        node = tmp;
    }
}
bool empty(Stack *s)
{
    return s->next == NULL;
}
