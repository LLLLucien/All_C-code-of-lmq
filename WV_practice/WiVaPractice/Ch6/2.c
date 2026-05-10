/*写程序，要求用户输入两个整数，然后计算并显示这两个整
数的最大公约数（GCD)*/
#include <stdio.h>
int main()
{
    int m, n, t;
    printf("Enter tow integers:");
    scanf("%d %d", &m, &n);
    while (1)
    {
        if (n == 0)
            break;
        if (m < n)
        {
            m = m + n;
            n = m - n;
            m = m - n;
        }
        t = m % n;
        m = n;
        n = t;
    }
    printf("Greatest common divisor:%d\n", m);

    return 0;
}