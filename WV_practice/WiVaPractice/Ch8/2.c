/*修改8.1节的程序repdigit.c ，使其打印出一份列表，显示
出每个数字在数中出现的次数*/

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen = false;
    int Repeat[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        Repeat[digit] += 1;
        n /= 10;
    }

    printf("Digit:\t\t");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", i);
    }
    printf("\n");
    printf("Occurrences:\t");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", Repeat[i]);
    }

    printf("\n");

    return 0;
}
