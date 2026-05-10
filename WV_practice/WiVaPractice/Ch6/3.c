/*写程序，要求用户输入一个分数，然后将其约分为最简分式*/
#include <stdio.h>
int main()
{
    int m, n, t, a, b;
    printf("Enter a fraction(X/X):");
    scanf("%d/%d", &a, &b);
    m = a;
    n = b;
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
    printf("In lowest terms:%d/%d\n", a / m, b / m);
    return 0;
}