// cut.c
// 切分文件
// 生成一个摘要信息meta.txt
// meta.txt存储每一片的哈希值，一行一个，最后一行是整体的哈希值
#include <openssl/evp.h>
// #include <openssl/md5.h>
// #include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void evp_to_md5(char *str);
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
        sprintf(cut_arr[i], "%s_%d_%d.%s", filename, i + 1, cut, dot);
    }
    for (int i = 0; i < cut; i++)
    {
        char buf[512];
        FILE *fp2 = fopen(cut_arr[i], "wb");
        int n = fread(buf, 1, sizeof(buf), fp1);
        fwrite(buf, 1, n, fp2);
        fclose(fp2);
    }
    // 计算每个文件的哈希值
    for (int i = 0; i < cut; i++)
    {
        evp_to_md5(cut_arr[i]);
    }
    // 计算整体的哈希值
    evp_to_md5(argv[1]);
    // free cut_arr
    for (int i = 0; i < cut; i++)
    {
        free(cut_arr[i]);
    }
    free(cut_arr);
    // 关闭
    fclose(fp1);
}

void evp_to_md5(char *str)
{
    unsigned char hash[EVP_MAX_MD_SIZE];
    EVP_MD_CTX *ctx = EVP_MD_CTX_new(); // 创建上下文
    EVP_DigestInit_ex(ctx, EVP_md5(), NULL); // 初始化上下文，指定摘要算法为MD5
    EVP_DigestUpdate(ctx, str,
                     strlen(str)); // 更新上下文，把数据和数据长度传进来

    // 得到实际哈希值的长度，因为hash是可以改的
    unsigned int len;
    EVP_DigestFinal_ex(ctx, hash, &len); // 得到哈希值的长度
    EVP_MD_CTX_free(ctx);                // 释放上下文

    FILE *fp = fopen("meta.txt", "a");
    if (!fp)
    {
        perror("文件无法打开\n");
        return;
    }
    // 打印哈希值
    for (int i = 0; i < len; i++)
    {
        fprintf(fp, "%02x", hash[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
}