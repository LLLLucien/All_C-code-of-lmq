// app.c
// 切分文件

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("请输入要切分的文件名\n");
        return EXIT_FAILURE;
    }
    FILE *fp1 = fopen(argv[1], "rb");
    if (!fp1)
    {
        perror("文件无法打开\n");
        return EXIT_FAILURE;
    }
    // 读取文件
    fseek(fp1, 0, SEEK_END);
    long size = ftell(fp1);
    // 重置文件指针
    fseek(fp1, 0, SEEK_SET);
    // 要切分的份数
    int cut = 0;
    if (size % 512 != 0)
    {
        cut = (size / 512) + 1;
    } else
        cut = size / 512;
    // 切分文件
    // 创建数组
    char **cut_arr = malloc(cut * sizeof(char *));
    if (!cut_arr)
    {
        perror("内存分配失败\n");
        return EXIT_FAILURE;
    }
    // 分配每个字符数组的内存
    for (int i = 0; i < cut; i++)
    {
        cut_arr[i] = malloc(sizeof(char) * 128);
    }
    // 检查内存分配是否成功
    for (int i = 0; i < cut; i++)
    {
        if (!cut_arr[i])
        {
            perror("内存分配失败\n");
            for (int j = 0; j < i; j++)
            {
                free(cut_arr[j]);
            }
            free(cut_arr);
            return EXIT_FAILURE;
        }
    }

    // 提取文件名
    char filename[128];
    char dot[64];

    strcpy(filename, argv[1]);

    // 提取文件的后缀名
    int is_dot = 0;
    while (1)
    {
        if (filename[is_dot] == '\0')
        {
            break;
        }
        if (filename[is_dot] != '.')
        {
            is_dot++;
            continue;
        } else
        {
            filename[is_dot] = '\0';
            is_dot++;
            sprintf(dot, "%s", filename + is_dot);
            break;
        }
    }
    printf("后缀提前成功\n");

    // 命名方式例如传入的文件为AAA.txt，如果分为4份
    // 则是AAA_1_4.txt、AAA_2_4.txt、AAA_3_4.txt、AAA_4_4.txt
    for (int i = 0; i < cut; i++)
    {
        sprintf(cut_arr[i], "%s_%d_%d.%s", filename, i, cut, dot);
    }
    for (int i = 0; i < cut; i++)
    {
        char buf[512];
        FILE *fp2 = fopen(cut_arr[i], "wb");
        int n = fread(buf, 1, sizeof(buf), fp1);
        fwrite(buf, 1, n, fp2);
        fclose(fp2);
    }
    // 关闭
    fclose(fp1);
}