// list.c
// 静态顺序表
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 16

// 声明操作
void init(List *l);
void add(List *l, char ch);
void show(List *l);
void insert(List *l, int n, char ch);
char delete(List *l, int index);
char get(List *l, int index);
int find(List *l, char ch);
bool empty(List *l);
void clear(List *l);

// ADT
typedef struct
{
    char data[MAX];
    // char *data2;
    int length;

} List;

int main()
{
    List list;
    char ch;
    int m;
    // printf("%ld", sizeof(list));
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    add(&list, 'E');
    add(&list, 'F');
    show(&list);
    insert(&list, 1, 'Z');
    show(&list);

    printf("%c\n", get(&list, 3));
    ch = delete(&list, 1);
    printf("已删除%c\n", ch);
    show(&list);

    printf("%d\n", find(&list, 'E'));
    return 0;
}

// 定义
// 初始化
void init(List *l)
{

    l->length = 0;
};
// 末尾添加
void add(List *l, char ch)
{
    if (l->length == MAX)
    {
        perror("满了\n");
        return;
    }

    l->data[l->length] = ch;

    l->length++;
};
// 打印内容
void show(List *l)
{
    printf("{");
    for (int i = 0; i < l->length; i++)
    {
        printf("%c,", l->data[i]);
    }
    // 使用\b退格
    printf("\b}\n");
};
// O(n)
void insert(List *l, int n, char ch)
{
    if (l->length >= MAX)
    {
        perror("满了1\n");
        return;
    }
    // 移动length
    for (int i = l->length - 1; i >= n; i--)
    {
        l->data[i + 1] = l->data[i];
    }
    l->data[n] = ch;
    l->length++;
}
char delete(List *l, int index)
{
    char ch = l->data[index];
    if (l->length <= index)
    {
        perror("不存在\n");
        return 0;
    }
    for (int i = index + 1; i < l->length; i++)
    {
        l->data[i - 1] = l->data[i];
    }

    l->length--;
    return ch;
}
// O(1)
char get(List *l, int index)
{
    // if (index >= l->length)
    //     return;
    return l->data[index];
}

int find(List *l, char ch)
{
    int index = -1;
    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] == ch)
        {
            index = i;
            break;
        }
    }
    return index;
}
bool empty(List *l)
{
    return l->length == 0;
}
void clear(List *l)
{
    l->length = 0;
}