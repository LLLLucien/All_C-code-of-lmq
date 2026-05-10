/*一个“B1FF过滤器”，它可以读取用户录入的消息并把此消
息翻译成B1FF的表达风格：*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *new;
    int i = 0;
    int j = 40;
    int m;
    char ch1[] = {'A', 'B', 'E', 'I', 'O', 'S'};
    char ch2[] = {'4', '8', '3', '1', '0', '5'};
    new = malloc(sizeof(char) * j);
    if (new == NULL)
    {
        printf("Error!");
        return 1;
    }
    printf("Enter message:");
    while (1)
    {

        if ((m = getchar()) == '\n' || m == EOF)
        {
            break;
        }
        else
        {
            char t = toupper((char)m);

            for (int k = 0; k < 6; k++)
            {
                if (t == ch1[k])
                {
                    t = ch2[k];
                    break;
                }
            }
            new[i] = t;
        }
        i++;
        if (i >= j)
        {
            j *= 2;
            char *temp = realloc(new, sizeof(char) * j);
            if (temp == NULL)
            {
                printf("Error!");
                free(new);

                return 1;
            }
            new = temp;
                }
    }
    new[i] = '\0';

    printf("In B1FF-speak: %s!!!!!!!!!!\n", new);
    free(new);
    new = NULL;
    return 0;
}