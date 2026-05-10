/*写程序颠倒句子中单词的顺序*/
/*用循环逐个读取字符，然后将它们存储在一个一维字符
数组中。当遇到句号、问号或者感叹号（称为“终止字符”）时，终
止循环并把终止字符存储在一个char 类型变量中。然后再用一个循
环反向搜索数组，找到最后一个单词的起始位置。显示最后一个单
词，然后反向搜索倒数第二个单词。重复这一过程，直至到达数组的
起始位置。最后显示出终止字符。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5
int is_word_char(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '\'');
}
int main()
{
    printf("输入英文句子（以.?!结束）:");
    char *a;
    a = malloc(sizeof(char) * N);
    if (a == NULL)
    {
        printf("内存分配错误\n");
        return 1;
    }
    int c = 0; // 数组下标
    int max_arr = N;
    char terminator = 0; // 存储终止字符（.?!）
    while (1)
    {
        int temp = getchar();
        if (temp == '.' || temp == '?' || temp == '!')
        {
            terminator = (char)temp;
            break;
        }
        if (temp == '\n' || temp == EOF)
            break;
        a[c] = (char)temp;
        c++;
        if (c >= max_arr - 1)
        {

            max_arr *= 2;
            char *temp2 = realloc(a, max_arr * sizeof(char));
            if (temp2 == NULL)
            {
                printf("内存分配错误\n");
                free(a); // 释放已分配内存
                return 1;
            }
            else
                a = temp2;
        }
    }

    a[c] = '\0';
    int end = c - 1;
    int t = 0;
    while (end >= 0)
    {
        while (end >= 0 && !is_word_char(a[end]))
            end--;
        if (end < 0)
            break;
        int start = end;
        while (start >= 0 && is_word_char(a[start]))
        {
            start--;
        }
        for (int i = start + 1; i <= end; i++)
            printf("%c", a[i]);
        // 单词之间加空格（最后一个单词后不加）
        if (start > 0)
        {
            printf(" ");
        }
        end = start - 1;
    }
    if (terminator != 0)
    {
        printf("%c\n", terminator);
    }
    else
    {
        printf("\n"); // 无终止字符时补换行
    }

    // 步骤5：释放内存（避免泄漏）
    free(a);
    return 0;
}