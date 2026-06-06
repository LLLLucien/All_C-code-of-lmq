// bit.c
// 位运算
#include <stdio.h>
int main()
{

    // 按位取反(十进制转二进制，不会倒叙)
    // 负数是通过按位取反再加一得到的
    // int a = 3;  //  0000 0011
    // int b = ~a; //  1111 1100 = -4
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < 32; i++)
    {
        // 0000 0000 0000 0000 0000 0011
        //
        printf("%d", (n >> (31 - i)) & 1);
        int b = 1 << (31 - i);
        printf("%d", (n & b) == b);
        }

    // 异或找不同
    //  int a[] = {12, 13, 42, 13, 15, 12, 15};
    //  int n = 0;
    //  for (int i = 0; i < 7; i++)
    //  {
    //      n = n ^ a[i];
    //  }
    //  printf("%d\n", n);

    // 异或运算^
    // int a = 2;
    // int b = 3;
    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;
    // printf("a=%d,b=%d\n", a, b);

    // 判断奇数
    //  int n;
    //  printf("请输入一个整数");
    //  scanf("%d", &n);
    //  if (n & 1 == 1)
    //  {
    //      printf("这个数是奇数\n");
    //  }
    //  else
    //  {
    //      printf("这个数是偶数\n");
    //  }

    return 0;
}