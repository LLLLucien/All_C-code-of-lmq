/*1. 编写一个程序，以月/日/年（即  ）的格式接受用户录
入的日期信息，并以年月日（即  ）的格式将其显示出来：*/
#include <stdio.h>
int main()
{
    int mm, dd, yy;
    printf("enter a Date(mm/dd/yy):\n");
    scanf("%d/%d/%d", &mm, &dd, &yy);
    printf("You entered the date %d%02d%d\n", yy, mm, dd);
    return 0;
}