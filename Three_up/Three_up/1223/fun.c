#include <stdio.h>
// 当前路径的自定义头文件
#include "my.h"
#include <stdbool.h>
// 声明、定义函数，参数：形式参数
// 模块化：高内聚、低耦合
// KISS原则：Keep It Simple Stupid 单一任务原则
// DRY原则：Don‘t Repeat Yourself
// 一个函数最好不超过100行

// 函数声明
// void print_array(int x[], int len);

int fact(int n)
{
    // 必须有收敛条件
    if (n == 1)
        return 1;
    // 一个函数调用自身
    return n * fact(n - 1);
}
int main()
{
    int a[] = {100, 200, 300, 400, 500};
    int b[20] = {0};
    // 函数调用

    printf("%d\n", fact(9));
    // print_array(a, 5); // x=a,,len=5
    // print_array(b, 5); // a,b 实际参数
    // for (int i = 0; i <= 100; i++)
    // {
    //     if (is_prime(i))
    //         printf("%d,", i);
    // }
    return 0;
}
