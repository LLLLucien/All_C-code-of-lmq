/*学常量e的值可以用一个无穷级数表示：*/
#include <stdio.h>
int main()
{
    int n;
    double e = 1;
    double f = 1;
    printf("Enter a number:");
    scanf("%d", &n);
    if (n == 0)
        printf("Error!\n");
    else
    {
        for (int i = 1; i <= n; i++)
        {
            f = f * i;
            e += (1.0 / f);
        }
        printf("e=%f\n", e);
    }
    return 0;
}
