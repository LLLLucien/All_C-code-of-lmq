/*改8.1节的程序repdigit.c ，使其可以显示出哪些数字有重
复（如果有的话）：*/
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

    printf("Repeated digit:");
    for (int i = 0; i < 10; i++)
    {
        if (Repeat[i] > 1)
        {
            printf(" %d", i);
            digit_seen = true;
        }
    }
    if (!digit_seen)
        printf("No repeated digit\n");
    printf("\n");

    return 0;
}
