/*利用switch 语句编写一个程序，把用数字表示的成绩转化为
字母表示的等级。*/
#include <stdio.h>
int main()
{
    int St;
    printf("Enter numerical grade:");
    scanf("%d", &St);
    St = St / 10;
    printf("Letter grade:");
    switch (St)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("F\n");
        break;
    case 6:
        printf("D\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 9:
    case 10:
        printf("A\n");
        break;

    default:
        printf("Wrong Number!\n");
        break;
        break;
    }
    return 0;
}