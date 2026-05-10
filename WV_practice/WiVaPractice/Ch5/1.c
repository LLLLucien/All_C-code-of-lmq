/*写一个程序，确定一个数的位数：*/
#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d", &num);
    if (num > 999)
    {
        printf("The number %d has 4 digits\n", num);
    }
    else if (num > 99)
    {

        printf("The number %d has 3 digits\n", num);
    }
    else if (num > 9)
    {
        printf("The number %d has 2 digits\n", num);
    }
    else
    {
        printf("The number %d has 1 digits\n", num);
    }
    return 0;
}