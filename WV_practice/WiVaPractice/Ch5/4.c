/*写一个程序，要求用户输入风速（海里/小时），然后显示相应
的描述*/
#include <stdio.h>
int main()
{
    int window;
    printf("输入风速（海里/小时）");
    scanf("%d", &window);

    if (window < 1)
    {
        printf("Calm\n");
    }
    else if (window <= 3)
    {
        printf("Light air\n");
    }
    else if (window <= 27)
    {
        printf("Breeze\n");
    }
    else if (window <= 47)
    {
        printf("Gale\n");
    }
    else if (window <= 63)
    {
        printf("Storm\n");
    }
    else
    {
        printf("Hurricane\n");
    }

    return 0;
}