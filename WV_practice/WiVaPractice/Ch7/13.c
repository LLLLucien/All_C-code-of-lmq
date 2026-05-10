/*写程序计算句子的平均词长*/
/*起见，程序中把标点符号看作其前面单词的一部分。平均词
长显示一个小数位*/
#include <stdio.h>
#include <string.h>
int main()
{
    long sum = 0;
    double len;
    int t, i;
    char word[50];
    i = 1;
    printf("输入一段英文:");
    while (1)
    {
        scanf("%s", word);
        sum += strlen(word);
        if ((t = getchar()) == '\n' || t == EOF)
        {
            break;
        }
        i++;
    }
    len = (double)sum / i;
    printf("平均词长:%.1f\n", len);
    return 0;
}