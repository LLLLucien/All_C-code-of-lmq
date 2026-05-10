/*新安排程序square3.c ，在for 循环中对变量i 进行初始
化、判定以及自增操作。不需要重写程序，特别是不要使用任何乘
法。*/
// 只是修改，不需要动代码
#include <stdio.h>

int main(void)
{
    int i, n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    i = 1;
    odd = 3;
    for (square = 1; i <= n; odd += 2)
    {
        printf("%10d%10d\n", i, square);
        ++i;
        square += odd;
    }

    return 0;
}
