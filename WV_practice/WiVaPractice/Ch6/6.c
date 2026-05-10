/*写程序，提示用户输入一个数  ，然后显示出1～  的所有偶
数平方值。例如，如果用户输入100，那么程序应该显示出下列内容：*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++)
    {
        if (!(i & 1))
            printf("%d\n", i * i);
    }
    return 0;
}