#include <stdio.h>
int *max(int *a, int *b)
{
    int *r;
    if (*a > *b)
        r = a;
    else
        r = b;
    return r;
}
int main(int argc, char const *argv[])
{
    int a = 9;
    int b = 1;
    int *p = max(&a, &b);

    return 0;
}
