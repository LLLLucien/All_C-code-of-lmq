/*写一个程序，要求用户输入一个两位数，然后显示该数的英
文单词：*/
#include <stdio.h>
int main()
{
    int Num;
    const char *ones[] = {"zero", "one", "two", "three", "four",
                          "five", "six", "seven", "eight", "nine"};
    // 整十数（10、20...90）：索引1对应ten，2对应twenty...9对应ninety
    const char *tens[] = {"", "ten", "twenty", "thirty", "forty",
                          "fifty", "sixty", "seventy", "eighty", "ninety"};
    // 特殊十几数（11-19）：索引1对应eleven，2对应twelve...9对应nineteen
    const char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    printf("Enter a two-digit number:");
    scanf("%d", &Num);
    printf("You entered the number: ");
    int a, b;
    a = Num / 10;
    b = Num % 10;

    if (Num < 10)
    {
        printf("%s\n", ones[Num]);
    }
    else if (b == 0)
    {
        printf("%s\n", tens[a]);
    }
    else if (Num < 20)
    {
        printf("%s\n", teens[b]);
    }
    else
    {
        printf("%s-%s\n", tens[a], ones[b]);
    }
}