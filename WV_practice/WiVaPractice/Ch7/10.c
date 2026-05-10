/*写程序统计句子中元音字母（a、e、i、o、u）的个数*/
#include <stdio.h>
#include <ctype.h>
int main()
{
    int a;
    int i = 0;
    printf("写一个英文句子:");
    while (1)
    {
        int c = getchar(); // 先接收原始值，区分字符/EOF
        a = tolower(c);    // 仅对原始字符转小写
        if (c != '\n' && c != EOF)
        {
            if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
                i++;
        }
        else
            break;
    }
    printf("句子中元音字母个数为:%d\n", i);

    return 0;
}