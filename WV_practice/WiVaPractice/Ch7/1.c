/*如果i * i 超出了int 类型的最大取值，那么6.3节的程序
square2.c 将失败（通常会显示奇怪的答案）。运行该程序，并确
定导致失败的n 的最小值。尝试把变量i 的类型改成short 并再次
运行该程序。（不要忘记更新printf 函数调用中的转换说明！）然
后尝试改成long 。从这些实验中，你能总结出在你的机器上用于存
储整数类型的位数是多少吗？*/
#include <stdio.h>

int main(void)
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        printf("%10d%10d\n", i, i * i);

    return 0;
}