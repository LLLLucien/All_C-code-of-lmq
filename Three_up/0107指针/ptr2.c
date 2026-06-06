#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 2;

    // 常量指针:值是常量，不可修改，*p=9 （X）
    int const *p = &a; // p->a
    printf("%d\n", *p);
    p = &b;
    printf("%d\n", *p);
    printf("%d\n", a);

    // 指针常量:地址是常量
    int *const p2 = &a;
    printf("%d\n", *p2);
    *p2 = b;
    printf("%d\n", a);

    // 指向常量的指针常量
    int const *const p3 = &a;
    printf("%d\n", *p3);
    printf("%p\n", p3);
    return 0;
}
