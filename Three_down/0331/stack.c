// stack.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 9

typedef struct stack
{
    char data[MAX]; // 顺序表
    int top;        // 栈顶指针
} Stack;

void init(Stack *s);
void push(Stack *s, char data);
char pop(Stack *s);
char top(Stack *s);
void clean(Stack *s);
bool empty(Stack *s);

// 操作
int main(int argc, char const *argv[])
{
    Stack s;
    init(&s);
    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'c');
    push(&s, 'd');
    while (!empty(&s))
        printf("%c,", pop(&s));
    printf("\b");
    // printf("\n");
    return 0;
}
void init(Stack *s)
{
    s->top = -1;
}
void push(Stack *s, char data)
{
    if (s->top == MAX - 1)
        return;
    s->data[++(s->top)] = data;
}
char pop(Stack *s)
{
    if (s->top == -1)
        return EXIT_FAILURE;
    return s->data[s->top--];
}
char top(Stack *s)
{
    return s->data[s->top];
}
void clean(Stack *s)
{
    s->top = -1;
}
bool empty(Stack *s)
{
    return s->top == -1;
}

void jisuan(Stack *s)
{
}