/*程测试两个单词是否为变位词（相同字母的重新排列）：*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 20
int main()
{
    int same_word[26] = {0};
    printf("该程序是用于测试两个单词是否为变位词（相同字母的重新排列）\n");
    char *word1 = malloc(sizeof(char) * N);
    char *word2 = malloc(sizeof(char) * N);
    int is_anagrams = 0;
    int max_arr1 = N;
    int max_arr2 = N;
    int c = 0;
    int c2 = 0;
    printf("输入第一个单词:");
    while (1)
    {
        int temp = getchar();

        if (temp == '\n' || temp == EOF)
            break;
        word1[c] = (char)temp;
        c++;
        if (c >= max_arr1 - 1)
        {

            max_arr1 *= 2;
            char *temp2 = realloc(word1, max_arr1 * sizeof(char));
            if (temp2 == NULL)
            {
                printf("内存分配错误\n");
                free(word1); // 释放已分配内存
                return 1;
            }
            else
                word1 = temp2;
        }
    }
    word1[c] = '\0';
    printf("输入第二个单词:");
    while (1)
    {
        int temp = getchar();

        if (temp == '\n' || temp == EOF)
            break;
        word2[c2] = (char)temp;
        c2++;
        if (c2 >= max_arr2 - 1)
        {

            max_arr2 *= 2;
            char *temp2 = realloc(word2, max_arr2 * sizeof(char));
            if (temp2 == NULL)
            {
                printf("内存分配错误\n");
                free(word2); // 释放已分配内存
                return 1;
            }
            else
                word2 = temp2;
        }
    }
    word2[c2] = '\0';
    if (c != c2)
    {
        printf("不是变位词\n");
        return 0;
    }
    int i = 0;
    while (word1[i] != '\0')
    {

        int temp = tolower(word1[i]);
        same_word[temp - 'a']++;
        i++;
    }
    int j = 0;

    while (word2[j] != 0)
    {
        int temp = tolower(word2[j]);
        if (same_word[temp - 'a'] > 0)
            same_word[temp - 'a']--;

        j++;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++)
        sum += same_word[i];
    if (sum != 0)
    {
        is_anagrams = 1;
        printf("不是变位词\n");
    }
    else
        printf("是变位词\n");
    free(word1);
    free(word2);
    return 0;
}