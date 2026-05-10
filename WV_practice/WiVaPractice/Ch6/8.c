/*写程序显示单月的日历。用户指定这个月的天数和该月起始
日是星期几*/
#include <stdio.h>
int main()
{
    int mm, dd, t;
    t = 0;
    printf("输入这个月有多少天");
    scanf("%d", &mm);
    printf("输入这周的第几天(周日=1,周六=7)");
    scanf("%d", &dd);
    printf("日 一 二 三 四 五 六\n");
    for (int i = 1; i < dd; i++)
    {
        printf("   ");
    }
    for (int i = 1; i <= mm; i++)
    {
        printf("%2d ", i);
        if ((i + dd - 1) % 7 == 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}