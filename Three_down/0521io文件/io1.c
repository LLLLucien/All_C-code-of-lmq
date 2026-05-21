// io1.c
// 字节操作
#include <stdio.h>

int main()
{
    // fopen参数：文件名，操作模式
    // 文件名：绝对路径 /home/lmq20233547/Three_down/0521io文件/test.txt
    // 文件名：相对路径 test.txt
    //  操作模式：w 写入模式，a 追加模式，r 读取模式，rb 二进制读取模式，wb
    // r+
    FILE *fp = fopen("test.txt", "r"); // 返回文件指针

    if (fp == NULL)
    {
        perror("wrong!无法打开文件");
        return 1;
    } else
        printf("文件打开成功\n");
    // 读取文件内容
    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp); // 关闭文件
    return 0;
}