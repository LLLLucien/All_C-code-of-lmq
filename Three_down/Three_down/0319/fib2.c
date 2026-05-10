#include <stdio.h>
long fib2(long n)
{
    long sum = 1;
    long a = 1;
    long b = 1;

    for (long i = 0; i < n - 2; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}
long main()
{
    long n = 50;
    // scanf("%d", &n);
    // printf("%ld\n", fib2(n));
    fib2(n);
    return 0;
}