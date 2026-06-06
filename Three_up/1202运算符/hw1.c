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
int main()
{
    int t;
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
    default:
        printf("404 notfound");
        break;
    }
}

int hw1()
{
    printf("请输入x，y，z，用逗号隔开：");
    int x, y, z;
    scanf("%d,%d,%d", &x, &y, &z);
    int max, mid, min, sum;
    sum = x + y + z;
    if (x >= y)
    {
        max = x > z ? x : z;
        if (max == x)
            min = y < z ? y : z;
        else
            min = x < y ? x : y;
        mid = sum - max - min;
    }
    else if (x >= z)
    {
        mid = x; // known y>x>z
        min = z;
        max = y;
    }
    else // known x<y,x<z
    {
        min = x;
        max = y > z ? y : z;
        mid = sum - max - min;
    }
    printf("x = %d,y = %d,z= %d\n", x, y, z);
    printf("max = %d,mid = %d,min= %d\n", max, mid, min);
    return 0;
}
/*写一个switch 语句，其控制表达式是变量area_code 。如
果area_code 的值在表中，switch 语句打印出相应的城市名；否
则switch 语句显示消息“Area code not recognized ”。使
用5.3节讨论的方法，使switch 语句尽可能简单。*/
int hw2()
{
    int area_code;
    printf("enter area_code:");
    scanf("%d", &area_code);
    switch (area_code)
    {
    case 404:
    case 470:
    case 678:
    case 770:
        printf("Atlanta");
        break;
    case 706:
    case 762:
        printf("Columbus");
        break;
    case 912:
        printf("Savannah");
        break;
    case 229:
        printf("Albany");
        break;
    case 478:
        printf("Macon");
        break;

    default:
        printf("Area code not recognized\n");
        break;
    }
    return 0;
}
// 写一个程序，确定一个数的位数
int hw3()
{
    int t = 0;
    int x = 0;
    printf("Enter a number: ");
    scanf("%d", &x);
    if (x < 10)
    {
        t = 1;
    }
    else if (x < 100)
    {
        t = 2;
    }
    else
    {
        t = 3;
    }
    printf("The number %d has %d digits\n", x, t);
    return 0;
}
/*写一个程序，要求用户输入24小时制的时间，然后显示12小
时制的格式*/
int hw4()
{
    printf("Enter a 24-hour time: ");
    int h, m, x, y;
    char d = 'A';
    scanf("%d:%d", &x, &y);
    h = x;
    m = y;

    if (h >= 24 || h < 0 || m >= 60 || m < 0)
    {
        printf("you input the wrong time!");
        return 0;
    }
    else if (h > 12)
    {
        h = h - 12;
        d = 'P';
    }
    else
    {
        if (h == 12)
        {
            h = 12;
            d = 'P';
        }
        h = h == 0 ? 12 : h;
    }

    printf("24-hour time: %d:%02d\n", x, y);
    printf("Equivalent 12-hour time: %d:%02d %cM\n", h, m, d);
    return 0;
}
/*改5.2节的broker.c 程序，同时进行下面两种改变。
  (a) 不再直接输入交易额，而是要求用户输入股票的数量和每股
的价格。
  (b) 增加语句用来计算经纪人竞争对手的佣金（少于2000股时佣
金为每股33美元+3美分，2000股或更多股时佣金为每股33美元+2美
分）。在显示原有经纪人佣金的同时，也显示出竞争对手的佣金*/
int hw5()
{

    float commission1, commission2, value, v;
    int num;
    printf("输入股票的数量: ");
    scanf("%d", &num);
    while (getchar() != '\n')
        ;
    printf("输入股票的数量和每股的价格: ");
    scanf("%f", &v);

    value = num * v;
    // 竞争对手
    if (num < 2000)
    {
        commission2 = num * 0.03f + 33;
    }
    else
    {
        commission2 = num * 0.02f + 33;
    }
    // 原来的
    if (value < 2500.00f)
        commission1 = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission1 = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission1 = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission1 = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission1 = 155.00f + .0011f * value;
    else
        commission1 = 255.00f + .0009f * value;

    if (commission1 < 39.00f)
        commission1 = 39.00f;

    printf("Commission1: $%.2f\n", commission1);
    printf("Commission2: $%.2f\n", commission2);

    return 0;
}
int hw6()
{
    float w;
    printf("风速（海里/小时）：");
    scanf("%f", &w);
    if (w < 1)
    {
        printf("无风\n");
    }
    else if (w < 4)
    {
        printf("轻风\n");
    }
    else if (w < 28)
    {
        printf("微风\n");
    }
    else if (w < 48)
    {
        printf("大风\n");
    }
    else if (w < 63)
    {
        printf("暴风\n");
    }
    else
    {
        printf("飓风\n");
    }

    return 0;
}
// 写一个程序，要求用户输入需纳税的收入，然后显示税金
int hw7()
{
    float m, i;
    printf("income:");
    scanf("%f", &m);
    if (m <= 750)
    {
        i = m * 0.01;
    }
    else if (m <= 2250)
    {
        i = 7.5f + 0.02 * (m - 750);
    }
    else if (m <= 3750)
    {
        i = 37.5f + 0.03 * (m - 2250);
    }
    else if (m <= 5250)
    {
        i = 82.5f + 0.04 * (m - 3750);
    }
    else if (m <= 7000)
    {
        i = 142.5f + 0.05 * (m - 5250);
    }
    else
    {
        i = 230.f + 0.06 * (m - 7000);
    }
    printf("税：%.3f", i);
    return 0;
}
/*修改4.1节的upc.c 程序，使其可以检测UPC的有效性。在用户
输入UPC后，程序将显示VALID 或NOT VALID*/
int hw8()
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
        first_sum, second_sum, total;

    printf("Enter the first (single) digit: ");
    scanf("%1d", &d);
    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
// 写一个程序，从用户输入的4个整数中找出最大值和最小值
int hw9()
{
    int a, b, c, d;
    int max, min;
    printf("Enter four integers:");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    max = a > b ? a : b;
    min = a < b ? a : b;

    max = max > c ? max : c;
    min = min < c ? min : c;

    max = max > d ? max : d;
    min = min < d ? min : d;
    printf("Largest: %d \nSmallest: %d", max, min);
    return 0;
}
/*一个程序，要求用户输入一个时间（用24小时制的时分表
示）。程序选择起飞时间与用户输入最接近的航班，显示出相应的起
飞时间和抵达时间*/
/*int hw10()
{
    printf("Enter a 24-hour time:");
    int h, m, t;
    scanf("%d:%d", &h, &m);
    t = h*60+m;

    if (h < 8)
    {
        printf("Closest departure time is ");
        printf("8:00 p.m., arriving at 10:16 p.m.");
    }
    else if (h < 9)
    {

        printf("Closest departure time is ");
        printf("8:00 p.m., arriving at 10:16 p.m.");
    }
    return 0;
}*/
int hw11()
{
    return 0;
}
/*写一个程序，提示用户输入两个日期，然后显示哪一个日期更
早：
*/
/*利用switch 语句编写一个程序，把用数字表示的成绩转化为
字母表示的等级*/
/*写一个程序，要求用户输入一个两位数，然后显示该数的英
文单词*/