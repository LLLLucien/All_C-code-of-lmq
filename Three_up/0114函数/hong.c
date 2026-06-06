#include <stdio.h>
#include "my.h"

int main()
{

    int num1 = 100;
    int num2 = 200;
    int num3 = 300;
    printf("%d\n", CAT(num, 1));
    printf("%d\n", CAT(num, 2));
    printf("%d\n", CAT(num, 3));
    printf("%d", my_max(3, 4));
    // int r = 5;
    // printf("%f\n", 2 * PI * r);
    // printf("%f\n", C(r + 1));
    // printf("%d\n", MUL(1, 3));
    //  参数不加括号，则是1+1*3+1
    //  参数加了括号，则（1+1）*（3+1）
    // printf("%d\n", MUL(1 + 1, 3 + 1));
    // printf("%d\n", MAX(789, 6));
    // printf("%s\n", TO_STR(PI));

    return 0;
}