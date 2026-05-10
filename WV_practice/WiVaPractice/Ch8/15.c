/*知的最古老的一种加密技术是凯撒加密（得名于Julius
Caesar）。该方法把一条消息中的每个字母用字母表中固定距离之后
的那个字母来替代。（如果越过了字母Z，会绕回到字母表的起始位
置。例如，如果每个字母都用字母表中两个位置之后的字母代替，那
么  就被替换为  ，  就被替换为  。）编写程序用凯撒加密方法
对消息进行加密。用户输入待加密的消息和移位计数（字母移动的位
置数目）：*/
#include <stdio.h>
#include <stdlib.h>
#define N 20
int is_Bigword_char(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}
int is_Smallword_char(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}
int main()
{
    char *a = malloc(sizeof(char) * N);
    int max_arr = N;
    int c = 0;
    int shift = 0;
    printf("输入需要加密(解密)的英文: ");
    while (1)
    {
        int temp = getchar();

        if (temp == '\n' || temp == EOF)
            break;
        a[c] = (char)temp;
        c++;
        if (c >= max_arr - 1)
        {

            max_arr *= 2;
            char *temp2 = realloc(a, max_arr * sizeof(char));
            if (temp2 == NULL)
            {
                printf("内存分配错误\n");
                free(a); // 释放已分配内存
                return 1;
            }
            else
                a = temp2;
        }
    }
    a[c] = '\0';
    printf("输入移位距离(1-25): ");
    scanf("%d", &shift);
    int start = 0;
    printf("加密(解密)结果: ");
    while (1)
    {
        if (is_Bigword_char(a[start]))
            printf("%c", ((a[start] - 'A') + shift) % 26 + 'A');
        else if (is_Smallword_char(a[start]))
            printf("%c", ((a[start] - 'a') + shift) % 26 + 'a');
        else
            printf("%c", a[start]);
        start++;
        if (start != '\0')
            break;
    }
    printf("\n");
    // 释放动态内存，避免泄漏
    free(a);
    return 0;
}