#include <stdio.h>
int hw1();
int hw2();
int hw3();
int hw4();
int hw5();
int hw6();
int main()
{
    int t;
    printf("请输入题目号：");
    scanf("%d", &t);
    switch (t)
    {
    case 1:
        hw1();
        break;
    case 2:
        hw2();
        break;
    case 3:
        hw3();
        break;
    case 4:
        hw4();
        break;
    case 5:
        hw5();
        break;
    case 6:
        hw6();
        break;

    default:
        break;
    }
}

int hw1()
{
    int mm, dd, yy;
    char a, b;
    printf("请输入月/日/年\n");
    scanf("%d%c%d%c%d", &mm, &a, &dd, &b, &yy);
    printf("%04d%02d%02d", yy, mm, dd);
    return 0;
}

int hw2()
{
    int num;
    double p;
    int mm, dd, yy;
    char a, b;
    printf("Enter item number:");
    scanf("%d", &num);
    printf("\nEnter unit price:");
    scanf("%lf", &p);
    printf("\nEnter purchase date (mm/dd/yyyy):");
    scanf("%d%c%d%c%d", &mm, &a, &dd, &b, &yy);
    printf("Item\tUnit\t\tPurchase\n\tPrice\t\tDate\n");
    printf("%d\t$%7.2f\t%02d/%02d/%04d\n", num, p, dd, mm, yy);
    return 0;
}
int hw3()
{
    long long a, b, c, d, e;
    printf("Enter ISBN:");
    scanf("%lld-%lld-%lld-%lld-%lld", &a, &b, &c, &d, &e);
    printf("\nGS1 prefix:%lld\n", a);
    printf("Group identifier:%lld\n", b);
    printf("Publisher code:%lld\n", c);
    printf("Item number:%lld\n", d);
    printf("Check digit:%lld\n", e);
    return 0;
};
int hw4()
{
    getchar();
    long long a, b, c;
    printf("Enter phone number [(xxx) xxx-xxxx]:");
    scanf("(%lld) %lld-%lld", &a, &b, &c);
    printf("\nYou entered: %lld.%lld.%lld\n", a, b, c);
    return 0;
};
int hw5()
{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16;
    int R1, R2, R3, R4, C1, C2, C3, C4, D1, D2;
    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          &a1, &a2, &a3, &a4,
          &a5, &a6, &a7, &a8,
          &a9, &a10, &a11, &a12,
          &a13, &a14, &a15, &a16);
    R1 = a1 + a2 + a3 + a4;
    R2 = a5 + a6 + a7 + a8;
    R3 = a9 + a10 + a11 + a12;
    R4 = a13 + a14 + a15 + a16;

    C1 = a1 + a5 + a9 + a13;
    C2 = a2 + a6 + a10 + a14;
    C3 = a3 + a7 + a11 + a15;
    C4 = a4 + a8 + a12 + a16;

    D1 = a1 + a6 + a11 + a16;
    D2 = a4 + a7 + a10 + a13;
    printf("\nRow sums:%d %d %d %d\n", R1, R2, R3, R4);
    printf("Column sums:%d %d %d %d\n", C1, C2, C3, C4);
    printf("Diagonal sums:%d %d\n", D1, D2);
};
int hw6()
{
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter first fraction: ");
    scanf("%d/%d%d/%d", &num1, &denom1, &num2, &denom2);
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}
