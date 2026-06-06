#include <stdio.h>
int main()
{

    // 成绩等级
    /*
    int n[4] = {60, 70, 80, 90};
    char level[6] = {'E', 'D', 'C', 'B', 'A'};
    printf("输入成绩：");
    int s, i = 0;
    scanf("%d", &s);
    for (; i < 4; i++)
    {
        if (s < n[i])
            break;
    }
    printf("成绩等级为%c\n", level[i]);
    */
    // 输入取款金额，输入面值多少张（总张数最少）
    // 879
    /*
    int rmb[6] = {100, 50, 20, 10, 5, 1};
    int n[6] = {0};
    int m, t;
    printf("rmb:");
    scanf("%d", &m);
    t = m;
    printf("金额：%d\n", t);
    for (int i = 0; i < 6; i++)
    {
        n[i] = m / rmb[i];
        m %= rmb[i];
        if (n[i] == 0)
            continue;
        printf("需要%2d 张面值 %3d元\n", n[i], rmb[i]);
    }
    */
    // 下标----------------
    /*
    int m;
    int day[] = {0, 31, 28, 31,
                 30, 31, 30, 31,
                 31, 30, 31, 30,
                 31};
    printf("月份：");
    scanf("%d", &m);
    if (m < 1 || m > 12)
    {
        printf("月份错误，重新输入！");
    }
    printf("%d月%d天\n", m, day[m]);
    */
    //--------------------
    // int a[6] = {0};
    // for (int i = 0; i < 6; i++)
    // {
    //     printf("a[%d]=%d\n", i, a[i]);
    // }
    return 0;
}