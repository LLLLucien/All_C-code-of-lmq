// io2.c
// 字节操作
#include <stdio.h>

int main()
{
    FILE *fp = fopen("b.txt", "a"); // 返回文件指针

    if (fp == NULL)
    {
        perror("wrong!无法打开文件");
        return 1;
    } else
        printf("文件打开成功\n");

    // 写(会截断，将覆盖原文件内容)
    fputc('\n', fp);
    fputc('A', fp);

    // 关闭
    fclose(fp);
    // 读取文件内容
}