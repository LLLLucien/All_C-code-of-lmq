#include <stdio.h>
int main()
{
    double x;
    double y;
    printf("请输入x的值：");
    scanf("%lf", &x);
    // y = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
    y = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("多项式3x^5+2x^4-5x^3-x^2+7x-6的值为：%.2f", y);
    return 0;
}