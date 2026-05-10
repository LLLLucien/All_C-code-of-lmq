/*写程序，生成一种贯穿N×N字符数组（初始时全为字符'.'
）的“随机步法”。程序必须随机地从一个元素 “走到”另一个元
素，每次都向上、向下、向左或向右移动一个元素位置。已访问过的
元素按访问顺序用字母A 到Z 进行标记。下面是一个输出示例*/
#include <stdio.h>
#include <stdlib.h> // rand/srand
#include <time.h>   // time(NULL)
#define N 10

int RRR(char (*a)[N], int i, int j, int K)
{

    if (i >= 0 && i < N && j >= 0 && j < N)
    {
        if (a[i][j] == '.')
        {
            a[i][j] = 'A' + K;
            return 1;
        }
        return 0;
    }
    else
        return 0;
}

int main()
{
    srand((unsigned int)time(NULL));
    char Table[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Table[i][j] = '.';

    // 65-90
    Table[0][0] = 'A';
    int i, j, up, down, left, right, K;
    i = 0;
    j = 0;
    K = 1;
    // 0上 1下 2左 3右
    while (1)
    {
        int t = rand() % 4;
        up = down = left = right = 0;
        if (i - 1 < 0 || Table[i - 1][j] != '.')
            up = 1;
        if (i + 1 >= N || Table[i + 1][j] != '.')
            down = 1;
        if (j - 1 < 0 || Table[i][j - 1] != '.')
            left = 1;
        if (j + 1 >= N || Table[i][j + 1] != '.')
            right = 1;
        // 死路直接退出，根源避免无限循环
        if (up == 1 && down == 1 && left == 1 && right == 1)
            break;
        if (K >= 26)
            break;
        switch (t)
        {
        case 0:
        {
            i = i - 1;
            if (!RRR(Table, i, j, K))
            {
                i = i + 1;
                up = 1;
            }
            else
            {
                K++;
                continue;
            }
        }
        break;
        case 1:
        {
            i = i + 1;
            if (!RRR(Table, i, j, K))
            {
                i = i - 1;
                down = 1;
            }
            else
            {
                K++;
                continue;
            }
        }
        break;

        case 2:
        {
            j = j - 1;
            if (!RRR(Table, i, j, K))
            {
                j = j + 1;
                left = 1;
            }
            else
            {
                K++;
                continue;
            }
        }
        break;
        case 3:
        {
            j = j + 1;
            if (!RRR(Table, i, j, K))
            {
                j = j - 1;
                right = 1;
            }
            else
            {
                K++;
                continue;
            }
        }
        break;
        default:
            break;
        }

        if (up == 1 && down == 1 && left == 1 && right == 1)
            break;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%c ", Table[i][j]);
        printf("\n");
    }
    return 0;
}