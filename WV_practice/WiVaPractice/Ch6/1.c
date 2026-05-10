/*写程序，找出用户输入的一串数中的最大数。程序需要提示用
户一个一个地输入数。当用户输入0或负数时，程序必须显示出已输入
的最大非负数*/
#include <stdio.h>
int main()
{
    float N = 0.f;
    float max = 0.f;
    int t = 0;
    while (1)
    {
        printf("Enter a number:");
        // 处理输入异常：判断scanf是否成功读取浮点数
        if (scanf("%f", &N) != 1)
        {
            printf("Input error! Please enter a valid number.\n");
            // 清空输入缓冲区，避免错误输入残留
            while (getchar() != '\n')
                ;
            continue; // 重新提示用户输入，而非直接终止
        }

        if (N <= 0 && t == 0)
        {
            printf("You didn't enter anything!\n");
            break;
        }
        else if (N <= 0)
        {
            printf("The largest number entered was %.2f\n", max);
            break;
        }
        max = N > max ? N : max;
        t = 1;
    }
    return 0;
}