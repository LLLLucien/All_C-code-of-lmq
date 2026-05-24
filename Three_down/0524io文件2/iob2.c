// iob2.c
#include <stdio.h>
#include <stdlib.h>
struct person {
    char name[16];
    int age;
};
int main()
{
    FILE *fp = fopen("a.data", "rb");
    if (!fp)
    {
        perror("文件打开失败\n");
        return EXIT_FAILURE;
    }
    // 读取文件内容
    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp); // 关闭文件
    return 0;   // 1
}
// 关闭文件
fclose(fp);
return EXIT_SUCCESS;
}