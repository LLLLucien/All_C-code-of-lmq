// bf算法
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int bf(char s_str[], char t_str[], int s_size, int t_size);
int main(int argc, char const *argv[])
{
    char s_str[] = "aadaaabcadc";
    char t_str[] = "adc";

    int s_len = sizeof(s_str) / sizeof(s_str[0]) - 1;
    int t_len = sizeof(t_str) / sizeof(t_str[0]) - 1;

    printf("主串长度：%d，模式串长度：%d\n", s_len, t_len);

    int pos = bf(s_str, t_str, s_len, t_len);
    if (pos != -1)
    {
        printf("匹配成功！起始下标：%d\n", pos);
    }
    else
    {
        printf("匹配失败！\n");
    }
    return 0;
}

int bf(char s_str[], char t_str[], int s_size, int t_size)
{
    int i, j, k;

    for (i = 0; i <= s_size - t_size; i++)
    {
        k = i;
        for (j = 0; j < t_size; j++)
        {
            if (s_str[k] == t_str[j])
            {
                if (j == t_size - 1)
                {
                    return i;
                }
                k++;
                continue;
            }
            break;
        }
    }
    return -1;
}
