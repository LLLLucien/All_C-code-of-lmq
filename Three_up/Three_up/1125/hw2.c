#include <stdio.h>
#define PI 3.14159265
int main()
{
    int r;
    printf("请输入整数的球的半径（m）：\n");
    scanf("%d", &r);
    double v;
    v = 4.0f / 3.0f * PI * r * r * r;
    printf("半径为%dm的球的体积为%.2fm³\n", r, v);
    return 0;
}