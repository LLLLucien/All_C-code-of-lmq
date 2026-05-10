#include <stdio.h>
/*展上题中的程序使其可以处理3位 数*/
int main()
{
    int num;
    int a, b, c;
    printf("Enter a three-digit number:");
    scanf("%d", &num);
    a = num / 100;
    b = (num % 100) / 10;
    c = num % 10;

    printf("The reversal is:%d%d%d\n", c, b, a);
    return 0;
}