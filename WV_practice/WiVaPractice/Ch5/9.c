/*写一个程序，提示用户输入两个日期，然后显示哪一个日期更
早：*/
#include <stdio.h>
// 方便输出结果
void PPP(int a, int mm1, int dd1, int yy1, int mm2, int dd2, int yy2);
int main()
{
    int mm1, dd1, yy1;
    int mm2, dd2, yy2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm1, &dd1, &yy1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm2, &dd2, &yy2);

    // 先比较年
    if (yy1 < yy2)
    {
        PPP(1, mm1, dd1, yy1, mm2, dd2, yy2);
    }
    else if (yy1 > yy2)
    {
        PPP(2, mm1, dd1, yy1, mm2, dd2, yy2);
    }
    // 再比较月
    else
    {
        if (mm1 < mm2)
        {
            PPP(1, mm1, dd1, yy1, mm2, dd2, yy2);
        }
        else if (mm2 < mm1)
        {
            PPP(2, mm1, dd1, yy1, mm2, dd2, yy2);
        }
        // 最后比较日
        else
        {
            if (dd1 < dd2)
            {
                PPP(1, mm1, dd1, yy1, mm2, dd2, yy2);
            }
            else if (dd2 < dd1)
            {
                PPP(2, mm1, dd1, yy1, mm2, dd2, yy2);
            }
            else
            {
                printf("两个日期相同\n");
            }
        }
    }
}
void PPP(int a, int mm1, int dd1, int yy1, int mm2, int dd2, int yy2)
{
    if (a == 1)
    {
        printf("%02d/%02d/%04d 比 %02d/%02d/%04d 早\n",
               mm1, dd1, yy1, mm2, dd2, yy2);
    }
    else
    {
        printf("%02d/%02d/%04d 比 %02d/%02d/%04d 早\n",
               mm2, dd2, yy2, mm1, dd1, yy1);
    }
}