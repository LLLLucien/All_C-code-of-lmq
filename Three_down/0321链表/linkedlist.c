// linkedlist
// 头插法实现单链表
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
// 节点
struct node
{
    ElemType data;     // 数据域
    struct node *next; // 指针域
    int length;
};

// 可以分开定义
typedef struct node Node;
typedef struct node LinkedList;
// 也可一起写
//  typedef struct node
//  {
//      ElemType data;     // 数据域
//      struct node *next; // 指针域
//  }Node,LinkedList;

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
    // 头节点
    LinkedList list;
    init(&list);
    int t = 0;
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    while (t != 1)
        t = menu(&list);
    // insert(&list, 'X', 4);
    // show(&list);
    // delete(&list, 1);
    // show(&list);
    // find(&list, 0);
    // clear(&list);
    // show(&list);
    return 0;
}

void init(LinkedList *l)
{
    // 空表：头节点的后继为空
    l->next = NULL;
    l->length = 0;
}
void add(LinkedList *l, ElemType ch)
{
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = l->next; // 把头节点所指的，赋给新的所指
    l->next = node;       // 让头节点指向新节点
    l->length++;
}
void show(LinkedList *l)
{
    // 首元
    Node *node = l->next;
    ElemType a[l->length];
    int i = 0;
    printf("{");
    int t = 0;
    while (node != NULL)
    {
        // printf("%c,", node->data);
        a[i++] = node->data;
        node = node->next;
        t = 1;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c,", a[j]);
    }
    if (t == 1)
        printf("\b}\n");
    else
        printf("}\n");
}
void insert(LinkedList *l, ElemType ch, int n)
{
    Node *node = l;
    if (n > l->length || n < 0)
    {
        printf("不存在该下标\n");
        return;
    }
    // 倒着加入，符合逻辑结构
    for (int i = l->length; i > n; i--)
    {
        node = node->next;
    }
    Node *new_node = malloc(sizeof(Node));
    new_node->data = ch;
    new_node->next = node->next; // 把头节点所指的，赋给新的所指
    node->next = new_node;       // 让头节点指向新节点
    l->length++;
    // add(node, ch);
}
void delete(LinkedList *l, int n)
{
    Node *node = l;
    if (n >= l->length || n < 0)
    {
        printf("不存在该下标\n");
        return;
    }
    // 倒着加入，符合逻辑结构
    for (int i = l->length; i > n + 1; i--)
    {
        node = node->next;
        // printf("%c\n", node->data);
        // printf("%d\n", i);
    }
    //  free(node->next->data);
    Node *tmp = node->next;
    node->next = tmp->next;
    free(tmp);

    l->length--;
}
void find(LinkedList *l, int n)
{
    Node *node = l;
    if (n >= l->length || n < 0)
    {
        printf("不存在该下标\n");
        return;
    }
    // 倒着加入，符合逻辑结构
    for (int i = l->length; i > n; i--)
    {
        node = node->next;
    }
    printf("%c\n", node->next->data);
}
void clear(LinkedList *l)
{
    if (l->next == NULL)
    {
        return;
    }
    Node *cur = l->next;
    while (cur != NULL)
    {
        Node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }

    l->next = NULL;
    l->length = 0;
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