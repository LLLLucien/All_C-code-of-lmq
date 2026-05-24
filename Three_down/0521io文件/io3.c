// io3.c
// 复制
#include <ctype.h>
#include <stdio.h>
int main()
{
    FILE *in = fopen("io1.c", "r");   // 返回文件指针
    FILE *out = fopen("io.txt", "w"); // 返回文件指针

    if (in == NULL || out == NULL)
    {
        perror("无法打开文件");
        return 1;
    } else
        printf("文件打开成功\n");

    int ch;
    while ((ch = fgetc(in)) != EOF)
    {
        if (isalpha(ch))
            ch++;
        fputc(ch, out);
    }
    // 检查并关闭文件
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        perror("文件关闭失败");
        return 1;
    } else
        printf("OK\n");
    // 关闭
    fclose(in);
    fclose(out);
}