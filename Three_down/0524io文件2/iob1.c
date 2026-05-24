// iob1.c
// binary file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[16];
    int age;
};

int main()
{
    struct person p1 = {"alice", 22};
    struct person p2;
    p2.age = 23;
    // 字符数组的赋值不能直接赋值，要使用strcpy函数
    // 除非是char *name
    strcpy(p2.name, "bob");

    // mode：wb、rb、ab
    // wb：写二进制文件
    // rb：读二进制文件
    // ab：追加二进制文件
    FILE *fp = fopen("a.data", "wb");

    if (!fp)
    {
        perror("文件打开失败\n");
        return EXIT_FAILURE;
    }

    // 写
    int n = 23;

    // 四个参数的意思
    // 指针：指向要写的数据
    // 大小：每个元素的大小
    // 数量：要写的数据的个数
    // 文件指针：要写入的文件
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(&p1, sizeof(struct person), 1, fp);
    fclose(fp);

    FILE *fp2 = fopen("a.data", "rb");
    if (!fp2)
    {
        perror("文件打开失败\n");
        return EXIT_FAILURE;
    }
    // 读
    int *a = malloc(sizeof(int));
    struct person *pp = malloc(sizeof(struct person));

    fread(a, sizeof(int), 1, fp2);
    fread(pp, sizeof(struct person), 1, fp2);

    printf("int=%d\n", *a);
    // 打印结构体内容
    printf("name=%s,age=%d\n", pp->name, pp->age);
    // 关闭文件

    fclose(fp2);
    return EXIT_SUCCESS;
}