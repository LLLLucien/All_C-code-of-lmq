/*写一个程序，要求用户输入一个美金数量，然后显示出如何用
最少的20美元、10美元、5美元和1美元来付款：*/
#include <stdio.h>
int main()
{
    int m;
    int m20, m10, m5, m1;
    printf("Enter a dollar amount:");
    scanf("%d", &m);
    int t = m;
    m20 = t / 20;
    t = t - 20 * m20;
    m10 = t / 10;
    t = t - 10 * m10;
    m5 = t / 5;
    t = t - 5 * m5;
    m1 = t;
    printf("$20 bills:%d\n", m20);
    printf("$10 bills:%d\n", m10);
    printf(" $5 bills:%d\n", m5);
    printf(" $1 bills:%d\n", m1);
    return 0;
}