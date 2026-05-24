// seek.c
#include <stdio.h>
#include <stdlib.h>

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
        perror("无法打开文件");
        return 1;
    }
    // 跳转到文件第10个字节
    // 文件指针、偏移量、参数
    // 参数：SEEK_SET 从文件开头开始跳转
    // SEEK_CUR 从当前位置开始跳转
    // SEEK_END 从文件末尾开始跳转
    fseek(fp, 0, SEEK_END);

    // ftell获取当前位置的偏移量,即可知道文件大小
    long size = ftell(fp);
    // 分配空间
    char *buf = malloc(size);
    // 文件指针移动到开头
    rewind(fp);
    // 一次读取size个字节
    fread(buf, 1, size, fp);
    printf("%s\n", buf);
    free(buf);

    // 关闭文件
    fclose(fp);
    return 0;
}