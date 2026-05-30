#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("temp.txt", "w");
    if (!fp)
    {
        perror("文件无法打开\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 200; i++)
    {
        fprintf(fp, "%d\n", 1);
    }
    fclose(fp);
    printf("写入成功\n");
    return 0;
}