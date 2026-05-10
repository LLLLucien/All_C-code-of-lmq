/*写程序要求用户输入12小时制的时间，然后用24小时制显示该
时间：*/
#include <stdio.h>
int main()
{
    int hh, mm;
    char c;
    printf("输入一个12小时制的时间(xx:xx AM/PM)");
    scanf("%d:%d", &hh, &mm);
    while (1)
    {
        if ((c = getchar()) == 'A' || c == 'P' || c == 'a' || c == 'p')
        {
            if (c == 'A' || c == 'a')
            {
                if (hh == 12)
                    // 12:00 ~12:59am
                    hh -= 12;
                else if (hh >= 1 && hh <= 11)
                    // 1:00~11:59am
                    ;
            }
            else if (c == 'P' || c == 'p')
            {
                // 12:00~11:59pm
                if (hh == 12)
                    ;
                else if (hh >= 1 && hh <= 11)
                    hh += 12;
            }
            break;
        }
    }
    printf("对应的24小时制的时间为:%02d:%02d\n", hh, mm);
    return 0;
}