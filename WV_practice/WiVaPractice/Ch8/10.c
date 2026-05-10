/*改第5章的编程题8，用一个数组存储起飞时间，另一个数组
存储抵达时间。（时间用整数表示，表示从午夜开始的分钟数。）程
序用一个循环搜索起飞时间数组，以找到与用户输入的时间最接近的
起飞时间*/
/*面的表格给出了一个城市到另一个城市的每日航班信息。*/
#include <stdio.h>
int sub(int m, int n);
int main()
{
    int hh, mm;
    int m_sum;
    int t;
    int startNum[] = {
        9 * 60 + 43,  // 9:43 a.m.
        11 * 60 + 19, // 11:19 a.m.
        12 * 60 + 47, // 12:47 p.m.
        14 * 60,      // 2:00 p.m.
        15 * 60 + 45, // 3:45 p.m.
        19 * 60,      // 7:00 p.m.
        21 * 60 + 45  // 9:45 p.m.
    };
    char *end[] = {
        "11:52 a.m.",
        "1:31 p.m.",
        "3:00 p.m.",
        "4:08 p.m.",
        "5:55 p.m.",
        "9:20 p.m.",
        "11:58 p.m."};
    char *start[] = {
        "9:43 a.m.",
        "11:19 a.m.",
        "12:47 p.m.",
        "2:00 p.m.",
        "3:45 p.m.",
        "7:00 p.m.",
        "9:45 p.m."};
    printf("Enter a 24-hour time:");
    scanf("%d:%d", &hh, &mm);
    // 转化为分钟
    m_sum = hh * 60 + mm;
    printf("Closest departure time is :");

    int close = 0; // 索引
    // 遍历所有出发时间，找到差值最小的那个
    for (int i = 1; i < 7; i++)
    {

        // 比较当前最近时间的差值 和 第i个时间的差值
        if (sub(startNum[close], m_sum) > sub(startNum[i], m_sum))
        {
            close = i;
        }
    }
    // 输出结果
    printf("%s,arriving at %s", start[close], end[close]);

    return 0;
}
int sub(int m, int n)
{
    if (m > n)
    {
        return m - n;
    }
    else
    {
        return n - m;
    }
}