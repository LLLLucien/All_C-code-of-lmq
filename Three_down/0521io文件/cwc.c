// 统计 C 源文件的总行数、空行数、注释行、代码行
#include <ctype.h>
#include <stdio.h>
#define MAX 1024

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("请加上一个参数：文件名\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }

    int all_lines = 0;     // 总行数
    int space_lines = 0;   // 空行数
    int comment_lines = 0; // 注释行
    int code_lines = 0;    // 代码行

    int is_empty = 0;         // 标记空行
    int is_comment = 0;       // 标记注释行
    int is_frist_comment = 1; // 标记首个是注释行

    char buf[MAX];
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        all_lines++;
        // 判断空行
        is_empty = 1;
        is_frist_comment = 1;
        is_comment = 0;
        for (int i = 0; buf[i] != '\0'; i++)
        {
            if (buf[i] == ' ' || buf[i] == '\t')
            {
                continue;
            }
            if (buf[i] == '\n')
            {
                break; // 行结束
            }
            // 没有提前结束，而且扫到了字符，不是空行，则会标记为0
            is_empty = 0;
        }
        if (is_empty)
        {
            space_lines++;
            continue;
        }
        // 判断注释行
        for (int i = 0; buf[i] != '\0'; i++)
        {
            // is_frist_comment = 1;
            if (buf[i] == ' ' || buf[i] == '\t')
            {
                continue;
            }

            // 存在”//“而且是首次出现则判断为注释行
            if (buf[i] == '/' && buf[i + 1] == '/')
            {
                is_comment = 1;
                break;
            } else
            {
                break;
            }
        }
        if (is_comment)
        {
            comment_lines++;
            continue;
        } else
        {
            code_lines++;
        }
    }

    printf("总行数=%d\n", all_lines);
    printf("空行数=%d\n", space_lines);
    printf("注释行=%d\n", comment_lines);
    printf("代码行=%d\n", code_lines);
}
