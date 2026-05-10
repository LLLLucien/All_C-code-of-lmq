/*编写一个程序，要求用户输入24小时制的时间，然后显示12小
时制的格式*/
#include <stdio.h>
int main()
{
    int hh, mm;
    printf("Enter a 24-hour time:");
    scanf("%d:%d", &hh, &mm);
    // 00:00-00:59 => 12:00-12:59+am
    if (hh == 0)
    {
        hh += 12;
        printf("Equivalent 12-hour time: %02d:%02d AM", hh, mm);
    }
    // 1:00-11:59 => 1:00-11:59+am
    else if (hh >= 1 && hh <= 11)
    {
        printf("Equivalent 12-hour time: %02d:%02d AM", hh, mm);
    }
    // 12:00-12:59 => 12:00-12:59+pm
    else if (hh == 12)
    {
        printf("Equivalent 12-hour time: %02d:%02d PM", hh, mm);
    }
    // 13:00-23:59 => 1:00-11:59+pm
    else if (hh >= 13 && hh <= 23)
    {
        hh -= 12;
        printf("Equivalent 12-hour time: %02d:%02d PM", hh, mm);
    }
    printf("\n");
    return 0;
}