/*写一个程序，读入用户输入的整数并按八进制（基数为8）显
示出来：*/
#include <stdio.h>
int main()
{
    int num = 0;
    int a[12] = {0};
    int i = 0;
    printf("Enter a number between 0 and 32767:");
    scanf("%d", &num);
    while (num != 0)
    {
        a[i] = num % 8;
        num = num / 8;
        i++;
    }
    printf("In octal, your number is:");
    for (int j = i; j >= 0; j--)
    {
        printf("%d", a[j]);
    }
    printf("\n");
    return 0;
}