/*改8.1节的程序interest.c ，使得修改后的程序可以每月
整合一次利息，而不是每年 整合一次利息。不要改变程序的输出格
式，余额仍按每年一次的时间间隔显示。*/
#include <stdio.h>

#define NUM_RATES ((int)(sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00
#define MONTHS_PER_YEAR 12 // 新增：定义一年的月份数，增强可读性

int main(void)
{
    int i, low_rate, num_years, year;
    int month; // 新增：月循环变量
    double value[5];
    double rate; // 新增：存储当前年利率（浮点数），避免重复计算

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++)
    {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++)
        {
            // 核心修改：替换原每年1次计息，改为12次每月计息
            rate = (low_rate + i) / 100.0;                    // 计算当前年利率（如5%→0.05）
            double monthly_rate = rate / MONTHS_PER_YEAR;     // 月利率=年利率/12
            for (month = 0; month < MONTHS_PER_YEAR; month++) // 每月计息一次
            {
                value[i] += monthly_rate * value[i]; // 每月累加月利息
            }

            printf("%7.2f", value[i]); // 输出格式完全不变
        }
        printf("\n");
    }

    return 0;
}