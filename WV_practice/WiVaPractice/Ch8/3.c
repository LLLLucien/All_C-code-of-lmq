/*改8.1节的程序repdigit.c ，使得用户可以录入多个数进行
重复数字的判断。当用户录入的数小于或等于0时，程序终止*/
#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen = false;
    int Repeat[10] = {0};
    int digit;
    long n;

    while (1)
    {
        printf("Enter a number: ");
        scanf("%ld", &n);
        if (n <= 0)
            break;
        while (n > 0)
        {
            digit = n % 10;
            Repeat[digit] += 1;
            n /= 10;
        }
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
