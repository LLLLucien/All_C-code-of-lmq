
/*修改6.3节的程序square2.c ，每24次平方后暂停并显示下列
信息：Press Enter to continue...*/
#include <stdio.h>

int main(void)
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    for (i = 1; i <= n; i++)
    {
        if (i % 25 == 0)
        {
            while (1)
            {

                printf("Press Enter to continue... ");
                if (getchar() == '\n')
                    break;
                else
                    continue;
            }
        }
        printf("%10d%10d\n", i, i * i);
    }
    return 0;
}