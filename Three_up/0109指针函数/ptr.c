// ptr.c
#include <stdio.h>

int R; // 全局变量

// 指针函数
// int *f(int a, int b)
// {
//     int r = a + b; // 局部变量
//     int *p = &r;
//     return p; // 返回了局部变量的地址，不可行
// }
void max(int *a, int len, int *r)
{
    // 基于指针形式的
    // 方法二：
    *r = a[0];

    for (int i = 0; i < len; i++)
    {

        if (*r < *a)
        {
            *r = *a;
        }
        a++;
    }
    // 方法一：
    //  int max = *a;
    //  for (int i = 0; i < len; i++)
    //  {
    //      printf("%d\n", *a);
    //      if (max < *a)
    //      {
    //          max = *a;
    //      }
    //      a = a + 1;
    //  }

    // 基于a[]下标形式的
    // int max = *a;
    //  for (int i = 0; i < len; i++)
    //  {
    //      if (a[i] > max)
    //          max = a[i];
    //  }
}
int main()
{
    int m[] = {12, 2, 42, 9, 5, 23, 7};
    int size = sizeof(m) / sizeof(m[0]); // 可得到数组长度
    // int r = max(m, size);
    int r;
    max(m, size, &r);
    printf("数组里最大的数是：%d\n", r);
    // int *p = f(1, 2);
    // printf("%p\n", p);
    // int *p1 = f(1, 2);
    // printf("%p\n", p1);
    return 0;
}