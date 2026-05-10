#include <stdio.h>
// 1.实现返回斐波那契数列第n个数,使用非递归算法。
int fib(int n);

// 2.实现参数是年、月、日,返回该日期是这一年的第多少天。
int days(int year, int month, int day);

// 3.有结构体 Date 表示日期,
// 请定义函数 diff 传入两个 Date 指针参数,返回两个日期相差多少天。
struct Date
{
    int year;
    int month;
    int day;
};
int diff(struct Date *a, struct Date *b);

int main()
{
    int n;
    printf("1.定义函数 int fib(int n) 返回斐波那契数列第n个数,使用非递归算法。\n");
    printf("请输入n的值:");
    scanf("%d", &n);
    printf("斐波那契数列第n个数为%d\n", fib(n));
    printf("2.定义函数 int days(int year, int month, int day) 参数是年、月、日,返回该日期是这一年的第多少天。\n");
    printf("请输入年月日,逗号隔开,例如（2026,3,15）\n");
    int year, month, day;
    scanf("%d,%d,%d,", &year, &month, &day);
    printf("%d\n", days(year, month, day));

    printf("3.有结构体 Date 表示日期,请定义函数 diff 传入两个 Date 指针参数,返回两个日期相差多少天。\n");
    printf("输入第一个日期的年月日,逗号隔开:\n");
    struct Date a;
    struct Date b;
    scanf("%d,%d,%d", &a.year, &a.month, &a.day);
    printf("输入第二个日期的年月日,逗号隔开:\n");
    scanf("%d,%d,%d", &b.year, &b.month, &b.day);
    diff(&a, &b);
    printf("日期%d-%d-%d与日期%d-%d-%d相隔%d天\n", a.year, a.month,
           a.day, b.year, b.month, b.day, diff(&a, &b));
    printf("\n");

    return 0;
}

// 实现返回斐波那契数列第n个数,使用非递归算法。
int fib(int n)

{
    int a = 1;
    int b = 1;
    int t = 0;
    if (n <= 2)
        return 1;
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            t = a + b;
            a = b;
            b = t;
        }
        return t;
    }
}

// 实现参数是年、月、日,返回该日期是这一年的第多少天。
int days(int year, int month, int day)
{
    // 1 3 5 7 8 10  12
    //  2 4 6   9  11
    // 判断是否为闰年的标志
    int R = 0;
    int sum = 0;

    // 不是闰年的年份
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 是闰年的年份
    int Rm[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 先判断是否是闰年
    if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
    {
        R = 1;
    }

    // 如果是闰年
    if (R = 1)
    {
        for (int i = 1; i < month; i++)
        {
            sum = sum + Rm[i];
        }
        sum = sum + day - 1;
    }
    // 如果不是闰年
    else
    {
        for (int i = 1; i < month; i++)
        {
            sum = sum + m[i];
        }
        sum = sum + day - 1;
    }
    return sum;
}

// 有结构体 Date 表示日期,
// 请定义函数 diff 传入两个 Date 指针参数,返回两个日期相差多少天。
int diff(struct Date *a, struct Date *b)
{
    // 直接调用前面写的计算该日期是这一年的第多少天
    int num1 = days(a->year, a->month, a->day);
    int num2 = days(b->year, b->month, b->day);
    int yearNUM = 0; // 年的相差
    int dayNUM = 0;  // 月日相差
    if (a->year == b->year)
    {
        return num1 > num2 ? num1 - num2 : num2 - num1;
    }
    else if (a->year > b->year)
    {

        for (int i = b->year; i < a->year; i++)
        {
            // 判断闰年
            if ((0 == i % 4 && 0 != i % 100) || 0 == i % 400)
            {
                yearNUM += 366;
            }
            else
                yearNUM += 365;
        }
    }
    else
    {
        for (int i = a->year; i < b->year; i++)
        {
            // 判断闰年
            if ((0 == i % 4 && 0 != i % 100) || 0 == i % 400)
            {
                yearNUM += 366;
            }
            else
                yearNUM += 365;
        }
    }
    dayNUM = num1 > num2 ? num1 - num2 : num2 - num1;
    return yearNUM + dayNUM - 1;
}