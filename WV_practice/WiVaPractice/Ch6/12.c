/*改编程题11，使得程序持续执行加法运算，直到当前项小于
为止，其中  是用户输入的较小的（浮点）数*/
#include <stdio.h>
int main()
{
    double n;
    double e = 1;
    double f = 1;
    double i = 1;
    printf("Enter a number:");
    scanf("%lf", &n);
    if (n <= 0)
    {
        printf("Error!\n");
        return 0;
    }
    while (1)
    {

        f = f * i;
        if ((1.0 / f) < n)
            break;
        e += (1.0 / f);
        i++;
    }
    printf("e=%f\n", e);
    return 0;
}
