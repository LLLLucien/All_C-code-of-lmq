/*5章的编程题9要求编写程序判断哪个日期更早。泛化该程
序，使用户可以输入任意个日期。用0/0/0指示输入结束，不再输入日
期。*/

#include <stdio.h>
// 方便输出结果
int Compare(int mm1, int dd1, int yy1, int mm2, int dd2, int yy2);
int main()
{
    int mm1, dd1, yy1;
    int mm2, dd2, yy2, t, d;
    d = 0;
    mm2 = 0;
    dd2 = 0;
    yy2 = 0;
    while (1)
    {
        printf("Enter date (mm/dd/yy): ");
        scanf("%d/%d/%d", &mm1, &dd1, &yy1);
        if (dd1 == 0 && mm1 == 0 && yy1 == 0)
            break;
        if (d == 0)
        {
            mm2 = mm1;
            dd2 = dd1;
            yy2 = yy1;
            d = 1;
        }
        else
        {
            t = Compare(mm1, dd1, yy1, mm2, dd2, yy2);
            if (t == 1)
            {
                mm2 = mm1;
                dd2 = dd1;
                yy2 = yy1;
            }
        }
    }
    if (dd2 == 0 && mm2 == 0 && yy2 == 0)
        printf("你未输入任何有效日期！\n");
    else
        printf("%02d/%02d/%04d 是最早的日期\n", mm2, dd2, yy2);
    return 0;
}
int Compare(int mm1, int dd1, int yy1, int mm2, int dd2, int yy2)
{
    // 先比较年
    if (yy1 < yy2)
    {
        return 1;
    }
    else if (yy1 > yy2)
    {
        return 2;
    }
    // 再比较月
    else
    {
        if (mm1 < mm2)
        {
            return 1;
        }
        else if (mm2 < mm1)
        {
            return 2;
        }
        // 最后比较日
        else
        {
            if (dd1 < dd2)
            {
                return 1;
            }
            else if (dd2 < dd1)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
    }
}