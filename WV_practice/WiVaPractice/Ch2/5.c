/*程要求用户输入  的值，然后显示如下多项式的值：

  提示 ：C语言没有指数运算符，所以需要对  进行自乘来计算其
幂。（例如，x*x*x 就是x 的三次方。）*/
#include <stdio.h>
int main()
{
    int x;
    int r;
    printf("enter a x:");
    scanf("%d", &x);
    r = 3 * x * x * x * x * x +
        2 * x * x * x * x -
        x * x * x * 5 -
        x * x +
        7 * x - 6;
    printf("result:%d\n", r);
    return 0;
}