/*写一个程序，要求用户（按任意次序）输入从1到16的所有整
数，然后用4×4矩阵的形式将它们显示出来，再计算出每行、每列和
每条对角线上的和*/
#include <stdio.h>
// 计算行和，n表示偏移量
int AddRow(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum + a[i + n];
    }
    return sum;
}
// 计算列和，n表示第几列
int AddCol(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum + a[i * 4 + n];
    }
    return sum;
}
// 计算对角线和
int AddDia(int a[], int t)
{
    int sum = 0;
    if (t == 5)
        for (int i = 0; i < 4; i++)
        {
            sum = sum + a[i * t];
        }
    else
        for (int i = 1; i <= 4; i++)
        {
            sum = sum + a[i * t];
        }
    return sum;
    // 0  1  2  3
    // 4  5  6  7
    // 8  9  10 11
    // 12 13 14 15
}
int main()
{
    int a[16];
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &a[i]);
        // while (getchar() != '\n')
        //     ;
    }
    for (int i = 0; i < 16; i++)
    {
        printf("%2d  ", a[i]);
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    int r1, r2, r3, r4;
    int c1, c2, c3, c4;
    int d1, d2;
    r1 = AddRow(a, 0);
    r2 = AddRow(a, 4);
    r3 = AddRow(a, 8);
    r4 = AddRow(a, 12);
    c1 = AddCol(a, 0);
    c2 = AddCol(a, 1);
    c3 = AddCol(a, 2);
    c4 = AddCol(a, 3);
    d1 = AddDia(a, 5);
    d2 = AddDia(a, 3);

    printf("Row sums:%d %d %d %d\n", r1, r2, r3, r4);
    printf("Column sums:%d %d %d %d\n", c1, c2, c3, c4);
    printf("Diagonal sums:%d %d\n", d1, d2);

    return 0;
}
