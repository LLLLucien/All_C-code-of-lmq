// io4.c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // int argc, char const *argv[]
    // 参数个数和参数
    // io4.c就是下标为0的参数
    for (int i = 0; i < argc; i++)
    {
        printf("%d %s\n", i, argv[i]);
    }
    if (argc != 3)
    {
        printf("请加上两个参数：源和目标\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if (fp == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    char buf[1024];
    // 后面会默认加一个‘\0’
    int c = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        fputs(buf, out);
        c++;
    }
    printf("c=%d\n", c);
    fclose(fp);
}
