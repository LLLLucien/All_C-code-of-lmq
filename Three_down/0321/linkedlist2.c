// linkedlist
// 尾插法实现单链表
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
// 节点
struct node
{
    ElemType data;     // 数据域
    struct node *next; // 指针域
};

typedef struct node Node;

// 定义链表
typedef struct linkedlist
{
    Node *head; // 头节点
    Node *r;    // 尾指针
    int length; // 大小
} LinkedList;

void init(LinkedList *l);
void add(LinkedList *l, ElemType ch);
void show(LinkedList *l);
// 插入、删除、查找、清空
void insert(LinkedList *l, ElemType ch, int n);
void delete(LinkedList *l, int n);
void find(LinkedList *l, int n);
void clear(LinkedList *l);
int menu(LinkedList *l);
int main(int argc, char const *argv[])
{
    LinkedList list;
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    int t = 0;
    while (t != 1)
        t = menu(&list);
    // add(&list, 'A');
    // add(&list, 'B');
    // add(&list, 'C');
    // add(&list, 'D');
    // show(&list);
    // insert(&list, 'X', 4);
    // // add(&list, 'E');
    // // add(&list, 'F');
    // show(&list);
    // delete(&list, 4);
    // show(&list);
    // // add(&list, 'G');
    // // add(&list, 'H');
    // // show(&list);

    // find(&list, 3);
    // clear(&list);
    // show(&list);

    return 0;
}

void init(LinkedList *l)
{
    // 创建头节点
    l->head = malloc(sizeof(Node));
    // 空表
    l->head->next = NULL;
    // 尾指针指向头节点
    l->r = l->head;
    l->length = 0;
}
void add(LinkedList *l, ElemType ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = NULL;

    // 最后一个元素的后继指向新节点
    l->r->next = node;
    // 尾指针指向新节点
    l->r = node;
    l->length++;
}
void show(LinkedList *l)
{
    int t = 0;
    Node *node = l->head->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
        t = 1;
    }
    if (t == 1)
        printf("\b}\n");
    else
        printf("}\n");
}
void insert(LinkedList *l, ElemType ch, int n)
{
    Node *node = l->head;
    Node *new_node = malloc(sizeof(Node));
    if (n > l->length || n < 0)
    {
        printf("不存在该下标\n");
        free(new_node);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        node = node->next;
    }

    new_node->data = ch;
    new_node->next = node->next;
    node->next = new_node;

    if (new_node->next == NULL)
    {
        // 最后一个元素的后继指向新节点
        l->r->next = new_node;
        // 尾指针指向新节点
        l->r = new_node;
        l->length++;
    }
    else
    {
        l->length++;
    }
}
void delete(LinkedList *l, int n)
{
    if (n >= l->length || n < 0)
    {
        printf("不存在该下标\n");
        return;
    }
    Node *node = l->head;
    // 找到上一个数据
    for (int i = 0; i < n; i++)
    {
        node = node->next;
    }
    Node *del_node = node->next;
    if (node->next->next != NULL)
    {
        node->next = del_node->next;
        free(del_node);
        l->length--;
    }
    else
    {
        node->next = del_node->next;
        l->r = node;
        l->r->next = node->next;
        free(del_node);
        l->length--;
    }
}
void find(LinkedList *l, int n)
{
    Node *node = l->head;
    if (n >= l->length || n < 0)
    {
        printf("不存在该下标\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        node = node->next;
    }
    printf("%c\n", node->next->data);
}
void clear(LinkedList *l)
{
    Node *cur = l->head->next; // 第一个有效节点
    while (cur != NULL)
    {
        Node *temp = cur->next; // 保存下一个节点
        free(cur);              // 释放当前节点
        cur = temp;             // 移动到下一个节点
    }

    // 重置链表状态为初始空表
    l->head->next = NULL;
    l->r = l->head; // 尾指针回到头节点
    l->length = 0;  // 长度置0
}
int menu(LinkedList *l)
{
    // ElemType ch;
    int chose;
    printf("请输入功能\n");
    printf("1.增加数据\n2.展示数据\n3.插入数据\n4.删除数据\n5.查找数据\n6.清空数据\n7.输入任意不存在的序号退出\n");
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
        int w1;

        printf("请输入要查找的位置:\n");
        scanf("%d", &w1);
        while (getchar() != '\n')
            ;
        find(l, w1);

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
    default:
        return 1;
        break;
    }
}