#include <stdio.h>
#include <string.h>
int main()
{
    char s1[] = "hello"; // 不可修改整体
    // s1 = "bye";不可改变
    //  但可以改变某个
    printf("%s\n", s1);
    s1[0] = 'B'; // 可以改
    printf("%c\n", s1);

    char *s2 = "hello"; // 不可修改某个
    printf("%s\n", s2);
    s2 = "bye"; // 可以改整体
    printf("%s\n", s2 + 1);
    // s2[0] = 'B'; 不可以

    // 错误的字符串，只是字符数组
    // char c1[] = {'A', 'e', 'l', 'l', 'o'};
    // char c2[] = {'A', 'B', 'C', 'D', 'E', '\0'}; // 必须包含‘/0’
    // char c3[5] = "hello";
    // char *c4 = "abcdef";

    // 要打印用%s
    // printf("c1=%s\t,空间=%lu,字符长度=%lu\n", c1, sizeof(c1), strlen(c1));
    // printf("c2=%s\t,空间=%lu,字符长度=%lu\n", c2, sizeof(c2), strlen(c2));
    // printf("c3=%s\t,空间=%lu,字符长度=%lu\n", c3, sizeof(c3), strlen(c3));
    // printf("c4=%s\t,空间=%lu,字符长度=%lu\n", c4, sizeof(c4), strlen(c4));
}