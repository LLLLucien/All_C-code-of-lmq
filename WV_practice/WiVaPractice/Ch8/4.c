/*改8.1节的程序reverse.c ，利用表达式(int)
(sizeof(a) / sizeof(a[0])) （或者具有相同值的宏）来计算
数组的长度*/

#include <stdio.h>

#define N 10

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < (int)(sizeof(a) / sizeof(a[0])); i++)
        scanf("%d", &a[i]);

    printf("In reverse order:");
    for (i = N - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
