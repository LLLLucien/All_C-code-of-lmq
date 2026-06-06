// 递归
#include <stdio.h>
int gcd(int n, int m);
int main()
{
    int n = 0;
    int m = 0;
    printf("输入两个整数：");
    scanf("%d %d", &n, &m);
    if (n < 0)
        n = 0 - n;
    if (m < 0)
        m = 0 - m;
    printf("%d\n", gcd(n, m));
}

int gcd(int n, int m)
{

    if (n < m)
    {
        int t = m;
        m = n;
        n = t;
    }
    if (m == 0)
        return n;
    if (n % m == 0)
        return m;
    return gcd(m, n % m);
}
