/*. 编写一个程序，要求用户输入一个两位数，然后按数位的逆序打
印出这个数。程序会话应类似下面这样：
Enter a two-digit number: 28


The reversal is: 82
  用%d 读入两位数，然后分解成两个数字。提示 ：如果n 是整
数，那么n % 10 是个位数，而n / 10 则是移除个位数后剩下的
数。*/
#include <stdio.h>
int main()
{
    int num;
    int a, b;
    printf("Enter a two-digit number:");
    scanf("%d", &num);
    a = num / 10;
    b = num % 10;
    printf("The reversal is:%d%d\n", b, a);
    return 0;
}