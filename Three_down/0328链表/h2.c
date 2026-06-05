// 荷兰国旗
// 元素去重
#include <stdio.h>
#include <stdlib.h>
#define count 12
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *prev;
    struct node *next;

} Node;

typedef struct List
{
    Node *head;
    Node *tail;
    int len;
} List;

void init(List *l);
void add(List *l, ElemType ch);
void insert(List *l, int index, ElemType ch);
void show(List *l);
Node *get(List *l, int index);
void helan(List *l);
void exchange(Node *a, Node *b);
void quchong(List *l);
void quchong2(List *l);
void delete(List *l, int index);

int main(int argc, char const *argv[])
{
    List list;
    init(&list);

    quchong2(&list);
    // helan(&list);

    return 0;
}

void init(List *l)
{
    l->head = malloc(sizeof(Node));
    l->head->next = NULL;
    l->head->prev = NULL;

    l->tail = l->head;
    l->len = 0;
}
void add(List *l, ElemType ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = NULL;
    node->prev = l->tail;
    l->tail->next = node;
    l->tail = node;
    l->len++;
}
void show(List *l)
{
    Node *node = l->head->next;
    printf("{ ");
    for (int i = 0; i < l->len; i++)
    {
        printf("%d,", node->data);
        node = node->next;
    }
    printf("\b}\n");
}
void insert(List *l, int index, ElemType ch)
{
    if (index < l->len)
    {
        Node *node = malloc(sizeof(Node));
        node->data = ch;
        Node *curr = get(l, index);

        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
        if (node->next == NULL)
        {
            l->tail = node;
        }
    }
    else
    {
        add(l, ch);
        return;
    }
    l->len++;
}
Node *get(List *l, int index)
{

    if (index < 0)
        return l->head;

    Node *node = l->head->next;
    // 如果超过下标，则最大只返回最后一个元素
    while (index > 0 && node->next != NULL)
    {
        node = node->next;
        index--;
    }

    return node;
}
void delete(List *l, int index)
{
    Node *node = get(l, index);

    if (index < 0)
    {
        printf("2");
        Node *tmp = l->head->next;
        l->head->next = l->head->next->next;
        l->head->next->prev = l->head;
        free(tmp);
    }
    else if (index >= 0)
    {
        if (node == l->tail)
        {

            l->tail = node->prev;
            node->prev->next = NULL;
            free(node);
            l->len--;
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;

        free(node);
    }
    l->len--;
}
void exchange(Node *a, Node *b)
{
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}
void helan(List *l)
{
    int a[count] = {1, 0, 2, 1, 0, 0, 1, 2, 2, 1, 0, 2};
    for (int i = 0; i < count; i++)
    {
        add(l, a[i]);
    }

    show(l);
    // helan(l);
    // show(l);

    int i = 0;
    int j = 0;
    int k = count;
    while (j < k)
    {
        // i++;
        // k--;
        // j++;
        if (get(l, j)->data == 0)
        {
            exchange(get(l, j), get(l, i));
            i++;
            continue;
        }
        else if (get(l, j)->data == 2)
        {
            exchange(get(l, j), get(l, k));
            k--;
            continue;
        }
        else
        {
            j++;
        }
    }
    show(l);
}

// 去重（只能判断整型）
void quchong(List *l)
{
    int a[] = {1, 2, 1, 2, 3, 2, 4, 4, 3, 4, 1, 2, 3, 4, 8};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        add(l, a[i]);
    }
    show(l);
    int b[15] = {0};
    Node *node = l->head->next;
    int i = 0;
    while (node->next != NULL)
    {
        Node *tmp = node->next;
        if (b[node->data] > 0)
        {
            b[node->data]++;
            delete(l, i);
            i--; // 由于删除了，下标不能变，用-1抵消后面的+1
        }
        else
        {
            b[node->data]++;
        }
        node = tmp;
        i++;
    }

    show(l);
}
// 去重（低效遍历去重）
void quchong2(List *l)
{
    int a[] = {1, 2, 1, 2, 3, 2, 4, 4, 3, 4, 1, 2, 3, 4, 8};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        add(l, a[i]);
    }
    Node *node = l->head->next;
    int j = 0;
    while (node != NULL)
    {
        int i = 0;
        printf("j=%d\n", j);
        Node *next = node->next;
        while (next != NULL)
        {
            i++;
            printf("i=%d\n", i);
            if (node->data == next->data)
            {
                Node *tmp = next->next;
                delete(l, j + i);

                next = tmp;
            }
            else
                next = next->next;
        }
        node = node->next;
        j++;
    }
    show(l);
}
