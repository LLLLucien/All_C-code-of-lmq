// 递归
#include <stdio.h>
int fb(int n);
int main()
{
    int n = 0;
    printf("(斐波那契数列)输入一个整数：");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%d ", fb(i));
    printf("\n");
}
// 1 1 2 3 5 8
int fb(int n)
{
    if (n >= 3)
    {
        return (fb(n - 1) + fb(n - 2));
    }
    else
        return 1;
}
