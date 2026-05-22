// 1.实现 wc 的核心功能，fgetc
// wc abc.c 行，单词，字节
#include <ctype.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("请加上一个参数：文件名\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    FILE *rfp = fopen(argv[1], "rb");

    if (fp == NULL || rfp == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }

    int line = 0;   // 行
    int word = 0;   // 单词
    int ifword = 0; // 用于判断单词
    int byte = 0;   // 字节
    int ch;

    // 统计行和单词数
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            line++;
        }
        if (!isalpha(ch))
        {
            ifword = 0; // 标记单词前面是非字母
        }
        // 如果找到字母，再看前面标记位是否0
        else if (ifword == 0)
        {
            // 不存在单词前面是非字母开头
            ifword = 1;
            // 除非遇到非字母，那么ifword才能变为0
            // 否则将视为字母都在单词整体里
            word++;
        }
    }
    // 统计字节数
    int ch2;
    while ((ch2 = fgetc(rfp)) != EOF)
    {
        byte++;
    }

    if (line > 0)
        line++;
    printf("行数=%d\n", line);
    printf("单词数=%d\n", word);
    printf("字节数=%d\n", byte);

    fclose(fp);
    fclose(rfp);
}