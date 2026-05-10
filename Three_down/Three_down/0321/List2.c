// 动态顺序表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_SIZE 3
#define MAX 10

typedef int ElemType;

typedef struct
{
    ElemType *data; // 容器
    int length;     // 长度
    int capacity;   // 容量
} List;

void init(List *l);
void add(List *l, ElemType e);
void grow(List *l);
void show(List *l);
int main()
{
    List list;
    init(&list);
    for (int i = 0; i < 20; i++)
    {
        add(&list, i);
    }
    show(&list);

    return 0;
}

void init(List *l)
{
    l->capacity = INIT_SIZE;
    l->data = malloc(INIT_SIZE * sizeof(ElemType));
    l->length = 0;
}

void add(List *l, ElemType e)
{
    grow(l);
    l->data[l->length] = e;
    l->length++;
}
void grow(List *l)
{
    if (l->length >= l->capacity)
    {
        // 扩容
        // 1.增长因子，+n
        // 2.增加2倍，1.5倍
        // n <<1  *2
        // n >>1  1/2
        int grow = l->capacity >> 1; //+ 1.5倍
        l->capacity += grow;
        ElemType *tmp = (ElemType *)realloc(l->data, sizeof(ElemType) * l->capacity);
        if (tmp == NULL)
        {
            perror("扩容失败");
            return;
        }
        printf("扩容至 %d\n", l->capacity);
        l->data = tmp;
    }
}
void show(List *l)
{
    printf("{");
    for (int i = 0; i < l->length; i++)
    {
        printf("%d,", l->data[i]);
    }
    // 使用\b退格
    printf("\b}\n");
};