#include <stdio.h>
long fib1(long n)
{
    if (n <= 1)
        return 1;
    else
        return fib1(n - 1) + fib1(n - 2);
}
int main()
{
    long n = 0;
    // scanf("%d", &n);
    // printf("%ld\n", fib1(n - 1));
    fib1(n - 1);
    return 0;
}