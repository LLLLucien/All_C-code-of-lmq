/*写程序，用牛顿方法计算正浮点数的平方根,平方根的猜测值
（我们使用1）*/
/*y的值逐渐接近x的平方根。为了获得更高的精度，程序
中应使用double 类型的变量代替float 类型的变量。当  的新旧
值之差的绝对值小于0.00001和  的乘积时程序终止。提示 ：调用
fabs 函数求double 类型数值的绝对值。（为了使用fabs 函数，
需要在程序的开头包含<math.h> 头。）*/
#include <stdio.h>
#include <math.h>
int main()
{
    double y = 1;
    double x, t, m;
    printf("输入一个数:");
    scanf("%lf", &x);
    while (1)
    {
        m = y;
        t = x / y;
        y = (y + t) / 2;
        if (fabs(y - m) < 0.00001 * y)
        {
            break;
        }
    }
    printf("%.2f的平方根为:%f\n", x, y);

    return 0;
}