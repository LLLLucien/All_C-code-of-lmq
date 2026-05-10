// double linked list
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct dnode
{
    ElemType data;      // 数据域
    struct dnode *prev; // 前驱
    struct dnode *next; // 后继
} Node;

typedef struct dlink
{
    Node *head;
    Node *tail;
    int len;
} List;

void add(List *l, ElemType ch);
void show(List *l);
void init(List *l);
void insert(List *l, int index, ElemType ch);
Node *get(List *l, int index);
void delete(List *l, int index);
// 清空，翻转
void clear(List *l);
void reverse(List *l);
int find(List *l, ElemType ch);
int menu(List *l);
int main()
{

    List list;
    init(&list);
    for (int i = 0; i < 5; i++)
    {
        insert(&list, i, 'A' + i);
    }
    int t = 0;
    while (t != 1)
        t = menu(&list);
    // printf("%c\n", get(&list, 1)->data);
    //  add(&list, 'A');
    //  add(&list, 'B');
    //  add(&list, 'C');
    //  add(&list, 'D');

    // printf("%d\n", find(&list, 'D'));

    // show(&list);
    // for (int i = 0; i < 5; i++)
    // {
    //     insert(&list, i, 'X');
    //     show(&list);
    //     delete(&list, i);
    // }

    // // // show(&list);
    // reverse(&list);
    // // //  clear(&list);
    // show(&list);
    // reverse(&list);
    // //  clear(&list);
    // show(&list);

    return 0;
}
void init(List *l)
{
    // 头节点
    l->head = malloc(sizeof(Node));
    // 指针域
    l->head->prev = l->head->next = NULL;
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

    if (!node)
    {
        printf("{}\n");
    }
    else
    {
        printf("{");
        while (node != NULL)
        {
            printf("%c,", node->data);
            node = node->next;
        }
        printf("\b}\n");
    }
}
Node *get(List *l, int index)
{
    // ToDo:从尾指针往前遍历

    Node *tmp = l->head->next;
    if (index >= 0 && index < l->len)
    {
        if (index <= l->len / 2)
        {
            for (int i = 0; i < index; i++)
            {
                tmp = tmp->next;
            }
        }
        else
        {
            tmp = l->tail;
            for (int i = l->len - 1; i > index; i--)
            {
                tmp = tmp->prev;
            }
        }
        return tmp;
    }
    else
    {
        return l->head;
    }
}
void insert(List *l, int index, ElemType ch)
{

    if (index < 0 || index > l->len)
        return;
    if (index == l->len)
    {
        add(l, ch);
        return;
    }

    Node *node = malloc(sizeof(Node));
    Node *tmp = get(l, index);
    node->data = ch;

    node->prev = tmp->prev;
    node->next = tmp;
    tmp->prev->next = node;
    tmp->prev = node;
    l->len++;
}

void delete(List *l, int index)
{
    Node *node = get(l, index);
    if (index > l->len - 1 || index < 0)
    {
        printf("不存在该下标\n");
        return;
    }
    // 跳过当前节点
    if (node->next != NULL)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    else
    {
        l->tail = node->prev;
        node->prev->next = NULL;
    }
    // 释放空间
    free(node);
    l->len--;
}
void clear(List *l)
{
    Node *tmp = l->head->next;
    while (tmp != NULL)
    {
        Node *node = tmp->next;
        free(tmp);
        tmp = node;
    }
    l->head->next = NULL;
    l->head->prev = NULL;
    l->tail = l->head;
}
void reverse(List *l)
{
    // 空,单个节点不用翻转
    if (l->len <= 1)
        return;
    Node *curr = l->head->next;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr)
    {
        next = curr->next; // 保存下一个
        curr->next = prev; // 翻转：如果是第一个元素，那么就指向了NULL
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    l->tail = l->head->next;
    l->head->next = prev;
    prev->prev = l->head; // 由于循环终止，最后的一个元素的前驱没有指向头，因此要改指向头

    /*
    Node *cur = l->head->next; // 从头开始
    // Node *old_tail = l->tail;
    Node *temp = NULL;

    while (cur != NULL)
    {
        temp = cur->next;      // 保存下一个节点
        cur->next = cur->prev; // 后继变前驱
        cur->prev = temp;      // 前驱变后继
        cur = temp;            // 当前节点移动到下一个
    }
    l->tail->prev = l->head; // 新头的前驱指向头节点
    temp = l->head->next;    // 保存旧首元
    temp->next = NULL;       // 旧首元要变最后元素，因此后继不再是其他元素，置空
    l->head->next = l->tail; // 让头节点的后继变为旧尾
    l->tail = temp;          // 旧尾变旧首元
    */
}
int find(List *l, ElemType ch)
{
    Node *node = l->head->next;
    for (int i = 0; i < l->len; i++)
    {
        if (node->data == ch)
            return i;
        else
            node = node->next;
    }
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
        insert(l, w2, ch2);
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
        {
            clear(l);
            printf("清空成功！当前元素为:\n");
            show(l);
        }
        printf("输入任意符号继续...\n");
        getchar();
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