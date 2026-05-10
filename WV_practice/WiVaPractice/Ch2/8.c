/*程计算第一、第二、第三个月还贷后剩余的贷款金额*/
/*显示每次还款后的余额时保留两位小数。提示 ：每个月的贷
款余额减去还款金额后，还需要加上贷款余额与月利率的乘积。月利
率的计算方法是把用户输入的利率转换成百分数再除以12*/
#include <stdio.h>
int main()
{
    double loan; // 贷款
    double rate; // 月利率
    double pay;  // 每月还款
    double m1, m2, m3;
    printf("Enter amount of loan:");
    scanf("%lf", &loan);
    printf("Enter interest rate:");
    scanf("%lf", &rate);
    printf("Enter monthly payment:");
    scanf("%lf", &pay);

    rate = rate * 0.01 / 12;
    m1 = loan - pay + loan * rate;
    loan = m1;
    m2 = loan - pay + loan * rate;
    loan = m2;
    m3 = loan - pay + loan * rate;
    loan = m3;

    printf("Balance remaining after first payment:%0.2f\n", m1);
    printf("Balance remaining after first payment:%0.2f\n", m2);
    printf("Balance remaining after first payment:%0.2f\n", m3);
    return 0;
}