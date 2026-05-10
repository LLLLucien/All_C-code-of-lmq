/*写一个程序，从用户输入的4个整数中找出最大值和最小值：*/
#include <stdio.h>
int main()
{
    int a, b, c, d;
    int max, min;
    printf("Enter four integers:");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    max = a;
    max = max > b ? max : b;
    max = max > c ? max : c;
    max = max > d ? max : d;

    min = a;
    min = b < min ? a : min;
    min = c < min ? b : min;
    min = d < min ? c : min;
    printf("max:%d\n", max);
    printf("min:%d\n", min);
    return 0;
}