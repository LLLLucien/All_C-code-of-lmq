// iob3.c
// 读取io1.c文件内容，写入bin.c文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *src = fopen("io1.c", "rb");
    FILE *dest = fopen("bin.c", "wb");

    if (!src || !dest)
    {
        perror("文件打开失败\n");
        return EXIT_FAILURE;
    }

    // 读取io1.c文件内容，写入bin.c文件
    char buf[32];

    int n;
    int c = 0;
    // n是指每次读取的字节数，c是指读取的次数
    while ((n = fread(buf, 1, sizeof(buf), src)) > 0)
    {
        // 写入n个字节,而不是sizeof(buf)，因为n是每次读取的字节数
        // 而如果写入sizeof(buf)，则会写入buf的全部内容，包括缓冲区的脏数据
        fwrite(buf, 1, n, dest);
        c++;
        printf("第%d次读取%d个字节\n", c, n);
    }
    // 关闭文件
    fclose(src);
    fclose(dest);
    return 0;
}