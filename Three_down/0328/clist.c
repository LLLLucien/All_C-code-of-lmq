// circle linked list
// 循环链表
// 循环单链表、循环双链表
#include <stdio.h>
#include <stdlib.h>

// 数据
typedef struct Node
{
    char data;
    struct Node *next;
} Node;
// 链表
typedef struct List
{
    Node *head;
    Node *tail;
} List;
// 操作
void init(List *l);
void show(List *l);
void add(List *l, char ch);
void insert(List *l, int index, char ch);
Node *get(List *l, int index);
void delete(List *l, int index);
// 清空，翻转
void clear(List *l);
void reverse(List *l);
int find(List *l, char ch);

int main()
{
    List list;
    init(&list);
    // add(&list, 'A');
    // add(&list, 'B');
    // add(&list, 'C');
    // add(&list, 'D');
    // show(&list);
    // clear(&list);
    add(&list, 'A');
    // insert(&list, 3, 'X');
    // show(&list);
    // delete(&list, 3);
    for (int i = 0; i < 5; i++)
    {
        insert(&list, i, 'X');
        show(&list);
        delete(&list, i);
    }
    // clear(&list);
    show(&list);
    printf("\n%c\n", get(&list, 0)->data);
    return 0;
}
void init(List *l)
{
    l->head = malloc(sizeof(Node));
    l->head->next = l->head;
    l->tail = l->head;
}
void add(List *l, char ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = l->head; // 指向头节点

    l->tail->next = node;
    l->tail = node;
}
void show(List *l)
{
    Node *node = l->head->next;
    printf("{ ");
    while (node != l->head)
    {
        printf("%c,", node->data);
        node = node->next;
        // if (node->next == l->head)
        // {
        //     printf("%c,", node->data);
        //     break;
        // }
    }
    printf("\b}\n");
}
Node *get(List *l, int index)
{
    Node *node = l->head->next;

    if (index < 0)
    {
        return l->head;
    }

    while (node->next != l->head && index > 0)
    {
        node = node->next;
        index--;
    }

    return node;
}
void insert(List *l, int index, char ch)
{
    Node *node = malloc(sizeof(Node));
    Node *prev = get(l, index - 1);
    if (prev->next != l->head->next)
    {
        node->data = ch;
        node->next = prev->next;
        prev->next = node;
    }
    if (prev == l->head)
    {
        node->data = ch;
        node->next = prev->next;
        prev->next = node;
    }
    if (node->next == l->head)
    {
        l->tail = node;
    }
}
void delete(List *l, int index)
{
    Node *prev = get(l, index - 1);
    // 判断是否为最后一个元素
    if (prev->next == l->head)
    {
        Node *node = l->head->next;
        // 找到倒数第二个元素
        while (node->next->next != l->head)
        {
            node = node->next;
        }
        // 跳过最后一个元素
        node->next = l->head;
        // 尾指针指向最后一个元素
        l->tail = node;
        // 释放当前元素
        free(prev);
        return;
    }

    Node *tmp = prev->next;
    prev->next = prev->next->next;
    if (prev->next == l->head)
    {
        l->tail = l->head;
    }
    free(tmp);
}
// 清空，翻转
void clear(List *l)
{
    Node *node = l->head->next;
    while (node != l->head)
    {
        Node *tmp = node->next;
        free(node);
        node = tmp;
    }
    l->head->next = node;
    l->tail = node;
}
void reverse(List *l);
int find(List *l, char ch);