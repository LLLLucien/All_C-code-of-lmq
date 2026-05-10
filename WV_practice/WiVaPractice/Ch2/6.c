/*改上题，用如下公式对多项式求值：

  注意，修改后的程序所需的乘法次数减少了。这种多项式求值方
法即Horner法则 （Horner's Rule）。*/
#include <stdio.h>
int main()
{
    int x;
    int r;
    printf("enter a x:");
    scanf("%d", &x);
    r = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("result:%d\n", r);
    return 0;
}