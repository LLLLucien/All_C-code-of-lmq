#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int kmp(char s_str[], char t_str[], int s_size, int t_size, int next[]);
void Getnext(int next[], int t_size, char t_str[]);
int main(int argc, char const *argv[])
{
    char s_str[] = "aaabcabaabcabd";
    char t_str[] = "abaabc";

    int s_len = sizeof(s_str) / sizeof(s_str[0]) - 1;
    int t_len = sizeof(t_str) / sizeof(t_str[0]) - 1;
    int next[6] = {0};

    Getnext(next, t_len, t_str);
    printf("主串长度：%d，模式串长度：%d\n", s_len, t_len);

    printf("next数组：");
    for (int i = 0; i < t_len; i++)
    {

        printf("%d,", next[i]);
    }
    printf("\b \n");
    int pos = kmp(s_str, t_str, s_len, t_len, next);
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
int kmp(char s_str[], char t_str[], int s_size, int t_size, int next[])
{
    int i, j;
    j = 0;
    for (i = 0; i < s_size;)
    {

        if (j < t_size)
        {
            if (s_str[i] == t_str[j])
            {
                if (j == t_size - 1)
                {
                    return i - j;
                }
                j++;
                i++;
            }
            else
            {
                j = next[j];
                // j = j - 1;
                if (j == -1)
                {
                    j = 0;
                    i++;
                }
                continue;
            }
        }
    }
    return -1;
}
void Getnext(int next[], int t_size, char t_str[])
{
    int j, k;
    j = 0;
    k = -1;
    next[0] = -1;
    while (j < t_size - 1)
    {
        // abcabd
        // 012345
        if (k == -1 || t_str[j] == t_str[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
            // j++;
        }
    }
}