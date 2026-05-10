/*改7.1节的程序sum2.c ，对double 型值组成的数列求和*/
#include <stdio.h>

int main(void)
{
    double n, sum = 0;

    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");

    scanf("%lf", &n);
    while (n != 0)
    {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %f\n", sum);

    return 0;
}