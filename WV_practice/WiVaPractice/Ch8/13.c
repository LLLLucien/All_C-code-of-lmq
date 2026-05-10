/*改第7章的编程题11，给输出加上标签：
写一个程序，根据用户输入的英文名和姓先显示姓氏，其后
跟一个逗号，然后显示名的首字母，最后加一个点*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    int a, p, t, m;
    p = 0;
    t = 0;
    m = 0;
    int big = 0;
    printf("输入一个英文名字(XXX XXX):");
    while (1)
    {
        a = getchar();
        if (a == '\n' || a == EOF)
        {
            break;
        }
        a = toupper(a);
        if (a >= 'A' && a <= 'Z' && t == 0)
        {
            p = a;
            t = 1;
        }
        else if (a == ' ' && t == 1)
        {
            t = 2;
            continue;
        }
        else if (a >= 'A' && a <= 'Z' && t == 2)
        {
            if (big == 0)
            {
                if (m == 0)
                    printf("You entered the name: ");

                printf("%c", a);
                big = 1;
                m = 1;
            }
            else
            {
                a = tolower(a);
                if (m == 0)
                    printf("You enered the name: ");
                printf("%c", a);
                m = 1;
            }
        }
    }
    printf(", %c.\n", p);
    return 0;
}