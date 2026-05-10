/*4章的编程题1要求编写程序显示出两位数的逆序。设计一个
更具一般性的程序，可以处理一位、两位、三位或者更多位的数。提
示 ：使用do 循环将输入的数重复除以10，直到值达到0为止*/
#include <stdio.h>
#include <stdlib.h>
int main()
{

    char *p;
    int i = 0;
    int j = 5;
    int ch;
    p = (char *)malloc(sizeof(char) * j);
    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return 1;
    }
    printf("这关程序将会输出数的逆序，请输入一个数");
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // 如果合法，就把输入的数存入数组里
        if (i >= j - 1)
        {
            j = i + 1;
            char *t = realloc(p, sizeof(char) * j);
            if (t == NULL)
            {
                printf("内存扩容失败！\n");
                free(p);
                return 1;
            }
            p = t;
        }
        p[i] = (char)ch;
        i++;
    }
    p[i] = '\0';

    for (int k = i - 1; k >= 0; k--)
    {
        printf("%c", p[k]);
    }
    printf("\n");
    printf("数组的大小是%ld\n", j * sizeof(p[0]));
    free(p);
    p = NULL;
    return 0;
}