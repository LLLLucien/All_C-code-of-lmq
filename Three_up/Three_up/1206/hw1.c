#include <stdio.h>
int hw1();
int hw2();
int hw3();
int hw4();
int hw5();
int hw6();
int hw7();
int hw8();
int hw9();
int hw10();
int hw11();
int hw12();
int main()
{
    int t;
    do
    {
        printf("请输入题号：");
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
        case 7:
            hw7();
            break;
        case 8:
            hw8();
            break;
        case 9:
            hw9();
            break;
        case 10:
            hw10();
            break;
        case 11:
            hw11();
            break;
        case 12:
            hw5();
            break;

        default:
            printf("Not found!Again!\n");
            t = 0;
        }
    } while (t == 0);
}
/*写程序，找出用户输入的一串数中的最大数。程序需要提示用
户一个一个地输入数。当用户输入0或负数时，程序必须显示出已输入
的最大非负数：*/
int hw1()
{
    // char ch = getchar();
    float n;
    float max = 0;
    do
    {
        printf("Enter a number:");
        scanf("%f", &n);
        max = max > n ? max : n;
    } while (n > 0);
    printf("The largest number entered was %.2f\n", max);
    return 0;
}
/*编写程序，要求用户输入两个整数，然后计算并显示这两个整
数的最大公约数（GCD）*/
int hw2()
{
    int m, n, t;
    printf("Enter two integers:");
    scanf("%d %d", &m, &n);
    while (n != 0)
    {
        t = m % n;
        m = n;
        n = t;
    }
    printf("公约数为：%d\n", m);
    return 0;
}
/*写程序，要求用户输入一个分数，然后将其约分为最简分式*/
int hw3()
{
    printf("输入一个分数（6/12）：");
    int m, n, t;
    scanf("%d/%d", &m, &n);
    int a, b;
    a = m;
    b = n;
    while (n != 0)
    {
        t = m % n;
        m = n;
        n = t;
    }
    printf("约分后:%d/%d\n", a / m, b / m);
    return 0;
}
/*5.2节的broker.c 程序中添加循环，以便用户可以输入多笔
交易并且程序可以计算每次的佣金。程序在用户输入的交易额为0时终
止*/
int hw4()
{
    float commission, value;
    while (1)
    {
        printf("Enter value of trade: ");
        scanf("%f", &value);
        if (value == 0)
            break;
        if (value < 2500.00f)
            commission = 30.00f + .017f * value;
        else if (value < 6250.00f)
            commission = 56.00f + .0066f * value;
        else if (value < 20000.00f)
            commission = 76.00f + .0034f * value;
        else if (value < 50000.00f)
            commission = 100.00f + .0022f * value;
        else if (value < 500000.00f)
            commission = 155.00f + .0011f * value;
        else
            commission = 255.00f + .0009f * value;

        if (commission < 39.00f)
            commission = 39.00f;

        printf("Commission: $%.2f\n", commission);
    }

    return 0;
}
/*4章的编程题1要求编写程序显示出两位数的逆序。设计一个
更具一般性的程序，可以处理一位、两位、三位或者更多位的数。提
示 ：使用do 循环将输入的数重复除以10，直到值达到0为止*/
int hw5()
{
    int t;
    int n;
    printf("输入一个整数：");
    scanf("%d", &n);
    printf("%d的逆序是：", n);
    while (0 != n)
    {
        t = n % 10;
        printf("%d", t);
        n /= 10;
    }
    printf("\n");
    return 0;
}
/*写程序，提示用户输入一个数  ，然后显示出1～  的所有偶
数平方值。例如，如果用户输入100，那么程序应该显示出下列内容*/
int hw6()
{
    int n;
    printf("输入一个整数：");
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++)
    {
        if (i % 2 == 0)
            printf("%d\n", i * i);
        continue;
    }
    return 0;
}
/*新安排程序square3.c ，在for 循环中对变量i 进行初始
化、判定以及自增操作。不需要重写程序，特别是不要使用任何乘
法*/
int hw7()
{
    int i, n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    i = 1;
    odd = 3;
    for (square = 1; i <= n; odd += 2)
    {
        printf("%10d%10d\n", i, square);
        ++i;
        square += odd;
    }

    return 0;
}
/*编写程序显示单月的日历。用户指定这个月的天数和该月起始
日是星期几*/
int hw8()
{
    int month;
    int day;
    int t; // 用于避免初始日期为1时仍然换行

    printf("输入一个月的天数：");
    scanf("%d", &month);
    printf("输入起始日期是一周的第几天(1=星期日, 7=星期六)：");
    scanf("%d", &day);
    if (day < 1 || day > 7)
    {
        printf("重新输入起始日期是一周的第几天(1=星期日, 7=星期六)：");
        scanf("%d", &day);
    }
    t = day;
    printf("日 一 二 三 四 五 六\n");
    for (int i = 1; i < day; i++)
    {
        printf("   ");
    }
    for (int i = 1; i <= month; i++)
    {

        if (t != 1)
            if ((i + day - 2) % 7 == 0)
                printf("\n");
        t = 0;
        printf("%2d ", i);
    }
    printf("\n");
    return 0;
}
int hw9()
{
    return 0;
}
int hw10()
{
    return 0;
}
int hw11()
{
    return 0;
}
int hw12()
{
    return 0;
}