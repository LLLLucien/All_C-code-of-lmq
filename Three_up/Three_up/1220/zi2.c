#include <stdio.h>
int main(int argc, char const *argv[])
{
    // char zi[]="壹";
    // char *zi = "壹"
    int m[9][9] = {0};
    for (int i = 0; i < 9; i++)
    {
        m[i][i] = 1;
        m[i][0] = 1;
        for (int j = 0; j < 9; j++)
        {
            if (i > 1 && j < i) // 可以减少计算量
            {
                m[i][j] = m[i - 1][j] + m[i - 1][j - 1];
            }
            if (m[i][j] != 0)
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
