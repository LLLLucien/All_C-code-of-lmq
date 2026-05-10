/*2章的编程题8要求编程计算第一、第二、第三个月还贷后剩余
的贷款金额。修改该程序，要求用户输入还贷的次数并显示每次还贷
后剩余的贷款金额*/
#include <stdio.h>
int main()
{
    double loan; // 贷款
    double rate; // 月利率
    double pay;  // 每月还款
    int i = 0;   // 还贷次数
    double m1, m2, m3;
    printf("请输入贷款本金（元）：");
    scanf("%lf", &loan);
    printf("请输入年利率（百分比，如5表示5%%）：");
    scanf("%lf", &rate);
    printf("请输入每月还款额（元）：");
    scanf("%lf", &pay);
    printf("还贷次数:");
    scanf("%d", &i);
    rate = rate * 0.01 / 12;
    for (int j = 1; j <= i; j++)
    {
        m1 = loan - pay + loan * rate;
        loan = m1;
        printf("第%d次还款后，剩余贷款金额:%0.2f元\n", j, m1);
    }
    return 0;
}