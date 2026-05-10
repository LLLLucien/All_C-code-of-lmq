#include <stdio.h>
int swap(int *a, int *b);
int main()
{

    int a, b;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("a=%d,b=%d\n", a, b);
    return 0;
}

int swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}