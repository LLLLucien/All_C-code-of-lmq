#include <stdio.h>
int main()
{
    //--------------------switch
    /*
    // 输入年和月，输出月多少天
    int year = 0, month, days;

    while (year != -1)
    {

        printf("请输入年和月(2000-9)：");
        scanf("%d-%d", &year, &month);
        while (getchar() != '\n')
            ;
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 2:
            // 判断是否为闰年
            if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
                days = 29;
            else
                days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = -1;
            break;
        }

        if (days == -1)
        {
            printf("年份%d月份无效:%d,月份为1~12的整数\n", year, month);
            month = 0;
        }
        else
            printf("%d年%d月有:%d天\n", year, month, days);
        year = year == -1 ? -1 : 0;
    }
    */
    //--------------------
    return 0;
}