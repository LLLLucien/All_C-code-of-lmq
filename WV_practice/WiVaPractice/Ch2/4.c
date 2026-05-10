/*编写一个程序，要求用户输入一个美元数量，然后显示出增加
5%税率后的相应金额。格式如下所示：*/
#include <stdio.h>
int main()
{
    double m;
    double t = 0.05;
    printf("Enter an amount:");
    scanf("%lf", &m);
    m = m * (1 + t);
    printf("With tax added:$%0.2f\n", m);
    return 0;
}