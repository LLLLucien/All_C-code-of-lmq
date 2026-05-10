// mem.c
// 动态内存管理
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char tel1[32];
    char *tel2;
};

char *cat(char *a, char *b)
{
    int size = strlen(a) + strlen(b) + 1;
    // 使用动态分配，可以返回局部变量的地址
    char *str = (char *)malloc(size);
    if (str)
    {
        strcpy(str, a);
        strcat(str, b);
    }
}
int main()
{
    struct User u1;
    // u1.tel1="123456";  字符数组之后不可以直接赋值
    strcpy(u1.tel1, "123456");

    u1.tel2 = malloc(12); // 这样分配后，可以进行修改

    u1.tel2 = calloc(1, 12); // 单位大小+多少个单位，分配后用0填充

    char *p = cat("hello", "c++");
    printf("%s\n", p);
    free(p);
    /*
    int a[6]; // 固定的

    // 由于返回的是void*，所有最好用强制转换
    int *p = (int *)malloc(sizeof(int) * 6); // 分配了24个字节
    // 分配后需要验证是否为空
    if (p == NULL)
    {
        perror("内存不足\n");
        return 1;
    }
    printf("%p\n", p);
    // 如果用完了，可以扩容
    p = realloc(p, sizeof(int) * 9); // 现在扩容到可以存储9个int的大小
    printf("%p\n", p);

    free(p);
    */
    return 0;
}