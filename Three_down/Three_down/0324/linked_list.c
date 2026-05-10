// linked_list.c
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 定义节点
struct node
{
    ElemType data;
    struct node *next;
};

typedef struct node Node;

// 定义链表
struct List
{
    Node *head; // 头节点
    Node *tail; // 尾指针，空表时指向头节点
    int len;
};

typedef struct List List;

// 初始化、增加、展示
void init(List *l);
Node *add(List *l, ElemType ch);
void show(List *l);
Node *get(List *l, int index);
// 插入、删除、查找、清空
Node *insert(List *l, ElemType ch, int index);
Node *delete(List *l, int index);

// 查找
int find(List *l, ElemType data);
// 清空
void clear(List *l);
// 翻转
void reverse(List *l);
int menu(List *l);
int main()
{
    List list;
    init(&list);

    int t = 0;
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    while (t != 1)
    {
        system("clear");
        t = menu(&list);
    }
    // show(&list);
    // printf("%d\n", find(&list, 'B'));
    // // printf("%c\n", get(&list, 0)->data);
    // // insert(&list, 'X', 0);
    // // delete(&list, 0);
    // // clear(&list);
    // reverse(&list);
    // show(&list);

    return 0;
}

// 初始化、增加、展示
void init(List *l)
{
    l->head = malloc(sizeof(Node));

    l->head->next = NULL;
    l->tail = l->head;
    l->len = 0;
}
Node *add(List *l, ElemType ch)
{
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    // 节点传入数据
    (*node).data = ch;
    node->next = NULL;
    // 让当前的最后一个元素的后继，变为新节点

    l->tail->next = node;
    // 让尾指针指向新节点
    l->tail = node;
    l->len++;
}
void show(List *l)
{
    Node *node = l->head->next;
    // 等价while(node)
    if (!node)
    {
        printf("{}\n");
    }
    else
    {
        printf("{");
        while (node != NULL)
        {
            printf("%c，", node->data);
            node = node->next;
        }
        printf("\b}\n");
    }
}
Node *get(List *l, int index)
{
    Node *node = l->head->next;
    if (index >= 0)
    {
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node;
    }
    else
        return l->head;
}
// 插入、删除、查找、清空

// O(1),不用关注get的复杂度
Node *insert(List *l, ElemType ch, int index)
{

    // 找到前驱
    Node *prev = get(l, index - 1);
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = prev->next;
    prev->next = node;
    l->len++;
}
Node *delete(List *l, int index)
{
    // 找到前驱
    Node *prev = get(l, index - 1);
    Node *tmp = prev->next;
    prev->next = tmp->next;
    free(tmp);
    l->len--;
}

void clear(List *l)
{
    Node *node = l->head->next;
    while (node != NULL)
    {
        Node *tmp = node->next;
        free(node);
        node = tmp;
    }
    l->tail = l->head;
    l->head->next = NULL;
}
int find(List *l, ElemType data)
{
    int i = 0;
    int if_find = 0;
    Node *node = l->head->next;
    for (; i < l->len; i++)
    {
        if (node->data == data)
        {
            if_find = 1;
            return i;
        }
        else
        {
            node = node->next;
        }
    }
    if (if_find == 0)
    {
        return -1;
    }
}
// h a b c d
void reverse(List *l)
{

    Node *now = l->head->next;
    Node *prev = NULL;
    Node *next = NULL;

    // Node *old_head = l->head;

    while (now != NULL)
    {
        next = now->next; // 找到下一个
        now->next = prev; // 下一个指向前一个
        prev = now;       // 前驱后移
        now = next;       // 当前的也后移
    }
    // Node *tmp2 = l->tail;
    l->tail = l->head->next;
    l->head->next = prev;
}

int menu(List *l)
{
    // ElemType ch;
    int chose;
    printf("====请输入功能====\n");
    printf("1.增加数据\n2.展示数据\n3.插入数据\n4.删除数据\n5.查找数据\n6.清空数据\n7.翻转链表\n8.输入任意不存在的序号退出\n");
    scanf("%d", &chose);
    while (getchar() != '\n')
        ;
    switch (chose)
    {
    case 1:
        ElemType ch1;
        printf("请输入要增加的元素:\n");
        scanf("%c", &ch1);
        while (getchar() != '\n')
            ;
        add(l, ch1);
        show(l);
        printf("输入任意符号继续...\n");
        getchar();
        break;
    case 2:
        show(l);
        printf("输入任意符号继续...\n");
        getchar();
        break;
    case 3:
        ElemType ch2;
        int w2;
        show(l);
        printf("请输入要插入的元素:\n");
        scanf("%c", &ch2);
        while (getchar() != '\n')
            ;
        printf("请输入要增加的位置:\n");
        scanf("%d", &w2);
        while (getchar() != '\n')
            ;
        insert(l, ch2, w2);
        show(l);
        printf("输入任意符号继续...\n");
        getchar();
        break;
    case 4:

        int w;
        show(l);
        printf("请输入要删除的位置:\n");
        scanf("%d", &w);
        while (getchar() != '\n')
            ;
        delete(l, w);
        show(l);
        printf("输入任意符号继续...\n");
        getchar();
        break;
    case 5:
        ElemType w1;

        printf("请输入要查找的元素:\n");
        scanf("%c", &w1);
        while (getchar() != '\n')
            ;
        printf("该元素的下表是%d\n", find(l, w1));

        printf("输入任意符号继续...\n");
        getchar();
        break;
    case 6:

        char ch3;
        printf("确定要清空数据？(Y/N):\n");
        scanf("%c", &ch3);
        while (getchar() != '\n')
            ;
        if (ch3 == 'Y' || ch3 == 'y')
            clear(l);

        break;
    case 7:
        char ch4;
        printf("确定要翻转元素吗？");
        scanf("%c", &ch3);
        while (getchar() != '\n')
            ;
        if (ch3 == 'Y' || ch3 == 'y')
            reverse(l);
        printf("翻转成功，当前的元素为:");
        show(l);
        printf("输入任意符号继续...\n");
        getchar();
        break;
    default:
        return 1;
        break;
    }
}