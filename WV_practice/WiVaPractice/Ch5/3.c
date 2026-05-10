/*改5.2节的broker.c 程序，同时进行下面两种改变。
  (a) 不再直接输入交易额，而是要求用户输入股票的数量和每股
的价格。
  (b) 增加语句用来计算经纪人竞争对手的佣金（少于2000股时佣
金为每股33美元+3美分，2000股或更多股时佣金为每股33美元+2美
分）。在显示原有经纪人佣金的同时，也显示出竞争对手的佣金。*/
#include <stdio.h>

int main(void)
{
    float commission, value, price;
    int num;
    printf("输入股票的数量: ");
    scanf("%d", &num);
    printf("输入每股的价格: ");
    scanf("%f", &price);

    value = num * price;

    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
        commission = 39.00f;

    printf("Commission: $%.2f\n", commission);
    // 竞争对手的佣金
    // 少于2000股时佣金为每股33美元+3美分
    if (num < 2000)
    {
        commission = 33.00f + 0.03f * num;
    }
    // 2000股或更多股时佣金为每股33美元+2美分
    else
    {
        commission = 33.00f + 0.02f * num;
    }
    printf("竞争对手的Commission: $%.2f\n", commission);
    return 0;
}
