// 判断回文
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
} List;

void init(List *l);
void add(List *l, char ch);
void show(List *l);
void huiwen(List *l);
Node *get(List *l, int index);
int main(int argc, char const *argv[])
{

    List list;
    init(&list);
    char a[] = {'a', 'b', 'a', 'a', 'b', 'a'};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        add(&list, a[i]);
    }

    show(&list);

    huiwen(&list);

    return 0;
}
void init(List *l)
{
    l->head = malloc(sizeof(Node));
    l->head->next = NULL;
    l->tail = l->head;
}
void add(List *l, char ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = l->tail->next;
    l->tail->next = node;
    l->tail = node;
}
void show(List *l)
{
    Node *node = l->head->next;
    printf("{ ");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
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
    while (index > 0 && node->next != NULL)
    {
        node = node->next;
        index--;
    }
    return node;
}
void huiwen(List *l)
{
    Node *slow = l->head->next;
    Node *fast = slow;

    int i = 0;
    int odd = 0;    // 0判断为奇数项
    int if_hui = 0; // 0判断为回文
    while (fast->next != NULL)
    {

        if (fast->next->next != NULL)
        {
            fast = fast->next->next;
        }
        else
        {
            odd = 1;
            break;
        }
        slow = slow->next;
        i++;
    }
    printf("odd=%d\n", odd);
    if (odd == 1)
    {
        Node *node1 = slow;
        Node *node2 = slow->next;
        printf("1a\n");
        while (node2 != NULL)
        {
            // printf("node1=%c\n", node1->data);
            // printf("node2=%c\n", node2->data);
            if (node1->data == node2->data)
            {

                // printf("node1=%c\n", node1->data);
                // printf("node2=%c\n", node2->data);
                // printf("ffi=%d\n", i);
                node1 = get(l, --i);
                // printf("i=%d\n", i);
                node2 = node2->next;
                continue;
            }
            if (node1->data != node2->data)
            {
                if_hui = 1;
                break;
            }
        }
    }
    else
    {

        Node *node1 = slow;
        Node *node2 = slow;
        while (node2 != NULL)
        {

            if (node1->data == node2->data)
            {

                node1 = get(l, --i);
                node2 = node2->next;
                continue;
            }
            if (node1->data != node2->data)
            {
                if_hui = 1;
                break;
            }
        }
    }
    printf("单链表：");
    show(l);
    printf("%s回文\n", if_hui > 0 ? "不是" : "是");
}