/*写一个程序，对用户录入的产品信息进行格式化。程序会话应
类似下面这样：*/
#include <stdio.h>
int main()
{
    int item_Num;
    double price;
    int mm, dd, yy;
    printf("Enter item number:");
    scanf("%d", &item_Num);
    printf("Enter unit price: ");
    scanf("%lf", &price);
    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &mm, &dd, &yy);

    printf("Item\tUnit\t\tPurchase\t\n");
    printf("\tPrice\t\tDate\t\n");
    printf("%d\t$%7.2f\t%02d/%02d/%04d\n", item_Num, price, mm, dd, yy);
    return 0;
}