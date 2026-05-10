#include <stdio.h>
int main()
{
    int m;
    printf("Enter an amount:");
    scanf("%d", &m);
    int a, b, c, d;
    a = m / 20;
    b = (m - 20 * a) / 10;
    c = (m - 20 * a - 10 * b) / 5;
    d = m - 20 * a - 10 * b - 5 * c;
    printf("$20 bills:%d\n", a);
    printf("$10 bills:%d\n", b);
    printf(" $5 bills:%d\n", c);
    printf(" $1 bills:%d\n", d);
}