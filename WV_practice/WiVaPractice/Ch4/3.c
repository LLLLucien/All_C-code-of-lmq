/*新编写编程题2中的程序，使新程序不需要利用算术分割就可
以显示出3位数的逆序。提示 ：参考4.1节的upc.c 程序。*/
#include <stdio.h>
int main()
{

    int a, b, c;
    printf("Enter a three-digit number:");
    scanf("%1d%1d%1d", &a, &b, &c);
    printf("The reversal is:%d%d%d\n", c, b, a);
    return 0;
}