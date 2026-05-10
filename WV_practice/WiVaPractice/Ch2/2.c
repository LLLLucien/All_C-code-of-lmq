/*写一个计算球体体积的程序，其中球体半径为10 m，参考公式
 。注意，分数4/3应写为4.0f/3.0f 。（如果分数写成
4/3 会产生什么结果？）提示 ：C语言没有指数运算符，所以需要对
 自乘两次来计算  */
#include <stdio.h>
#define P 3.1415
int main()
{
    int R = 10;
    double V = 0;
    V = (4.0 / 3.0) * P * R * R * R;
    printf("V=%f\n", V);
    return 0;
}