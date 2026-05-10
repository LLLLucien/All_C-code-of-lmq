/*美国的某个州，单身居民需要担负下面表格列出的所得税*/
#include <stdio.h>
int main()
{
    double m, tax;
    printf("Momey:");
    scanf("%lf", &m);
    if (m <= 750)
    {
        tax = m * 0.01;
    }
    else if (m <= 2250)
    {
        tax = 7.5 + (m - 750) * 0.02;
    }
    else if (m <= 3750)
    {
        tax = 37.5 + (m - 2250) * 0.03;
    }
    else if (m <= 5250)
    {
        tax = 82.5 + (m - 3750) * 0.04;
    }
    else if (m <= 7000)
    {
        tax = 142.5 + (m - 5250) * 0.05;
    }
    else
    {
        tax = 230.0 + (m - 7000) * 0.06;
    }
    printf("tax:%.2f", tax);
    return 0;
}