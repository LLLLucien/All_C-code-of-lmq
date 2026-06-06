// 循环
#include <stdio.h>
int fb(int n);
int main()
{
    int n = 0;
    int a = 1;
    int b = 1;
    int t[2] = {1, 1};
    int sum = 0;
    printf("(斐波那契数列)输入一个整数：");
    scanf("%d", &n);
    // 第一个与第二个特殊处理
    if (n <= 2)
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", a);
        }
    else
    {
        for (int i = 1; i <= 2; i++) // 先打印前两个
        {
            printf("%d ", a);
        } // 接着打印剩余的
        while (n - 2 > 0) // 因为已经默认打印了两个，所以只需要n-2次
        {
            sum = t[0] + t[1];
            t[0] = t[1];
            t[1] = sum;
            n--;
            printf("%d ", sum);
        }
    }
    printf("\n");
}
// 1 1 2 3 5 8
