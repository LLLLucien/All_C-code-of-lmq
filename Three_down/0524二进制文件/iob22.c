// iob22.c
// binary file
// 写入多个结构体
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[16];
    int age;
};

int main()
{
    struct person list[3] = {{"alice", 22}, {"bob ", 23}, {"charlie", 24}};

    FILE *fp = fopen("a.data", "wb");

    if (!fp)
    {
        perror("文件打开失败\n");
        return EXIT_FAILURE;
    }

    // 写入3个结构体，每个结构体的大小为sizeof(struct person)，写入3个

    fwrite(list, sizeof(struct person), 3, fp);

    fclose(fp);

    // 读
    FILE *fp2 = fopen("a.data", "rb");
    if (!fp2)
    {
        perror("文件打开失败\n");
        return EXIT_FAILURE;
    }

    // 一个指针1个结构体，读取3个结构体
    struct person *p1 = malloc(sizeof(struct person));
    struct person *p2 = malloc(sizeof(struct person));
    struct person *p3 = malloc(sizeof(struct person));

    fread(p1, sizeof(struct person), 1, fp2);
    fread(p2, sizeof(struct person), 1, fp2);
    fread(p3, sizeof(struct person), 1, fp2);

    printf("name=%s,age=%d\n", p1->name, p1->age);
    printf("name=%s,age=%d\n", p2->name, p2->age);
    printf("name=%s,age=%d\n", p3->name, p3->age);

    // 使用数组一次就读取3个结构体
    rewind(fp2);
    struct person pa[3];
    fread(pa, sizeof(struct person), 3, fp2);
    printf("name=%s,age=%d\n", pa[0].name, pa[0].age);
    printf("name=%s,age=%d\n", pa[1].name, pa[1].age);
    printf("name=%s,age=%d\n", pa[2].name, pa[2].age);
    // 关闭文件

    free(p1);
    free(p2);
    free(p3);

    // 关闭文件

    fclose(fp2);
    return EXIT_SUCCESS;
}