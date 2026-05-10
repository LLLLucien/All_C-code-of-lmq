// 写一个程序，要求用户输入一个美金数量，然后显示出如何用
// 最少的20美元、10美元、5美元和1美元来付款：
// Enter a dollar amount : 93

//     $20 bills : 4 $10 bills : 1 $5 bills : 0 $1 bills : 3
#include <stdio.h>
void pay_amount(int dollars, int *twenties, int *tens, int *fives,
                int *ones)
{
    *twenties = dollars / 20;
    dollars = dollars - 20 * *twenties; // 减去取完的值
    *tens = dollars / 10;
    dollars = dollars - 10 * *tens;
    *fives = dollars / 5;
    dollars = dollars - 5 * *fives;
    *ones = dollars;
}
int main()
{
    printf("Enter a dollar amount :");
    int dollars = 0;
    int twenties = 0, tens = 0, fives = 0, ones = 0;
    scanf("%d", &dollars);
    // 将变量的地址传入函数
    pay_amount(dollars, &twenties, &tens, &fives, &ones);
    printf("$20 bills :%d\n", twenties);
    printf("$10 bills :%d\n", tens);
    printf("$5 bills :%d\n", fives);
    printf("$1 bills :%d\n", ones);
}