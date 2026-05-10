#include <stdio.h>
#include <stdbool.h>
// 构成：函数名，参数列表，函数体，返回类型
// 函数定义
void print_array(int x[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}
bool is_prime(int n)
{
    bool flag = true;
    // 2~n-1
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}