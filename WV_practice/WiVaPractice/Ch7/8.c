/*改第5章的编程题8，要求用户输入12小时制的时间。输入时间
的格式为时∶分 后跟A、P、AM或PM（大小写均可）。数值时间和
AM/PM之间允许有空白（但不强制要求有空白）。有效输入的示例如
下：*/
/*
*********还未修复的问题********
输入格式错误：未按数字:数字格式输入（比如输入a:12/12;30/12-30/abc，scanf读取失败）；
小时值非法：12 小时制的小时只能是1~12（不存在 0、13 及以上的小时，比如输入0:30 AM/13:20 PM）；
分钟值非法：分钟只能是0~59（不存在 60 及以上的分钟，比如输入9:60 AM/12:78 PM）；
缺少 AM/PM 标识：输入时间后无任何A/a/P/p字符（比如输入12:30后直接回车，未输入 AM/PM 相关标识）。
*/
#include <stdio.h>
int sub(int m, int n);
int main()
{
    int hh, mm;
    int m_sum;
    int t;
    char c;
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

    printf("输入一个12小时制的时间(xx:xx AM/PM)");
    scanf("%d:%d", &hh, &mm);
    while (1)
    {
        if ((c = getchar()) == 'A' || c == 'P' || c == 'a' || c == 'p')
        {
            if (c == 'A' || c == 'a')
            {
                if (hh == 12)
                    // 12:00 ~12:59am
                    hh -= 12;
                else if (hh >= 1 && hh <= 11)
                    // 1:00~11:59am
                    ;
            }
            else if (c == 'P' || c == 'p')
            {
                // 12:00~11:59pm
                if (hh == 12)
                    ;
                else if (hh >= 1 && hh <= 11)
                    hh += 12;
            }
            break;
        }
    }

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