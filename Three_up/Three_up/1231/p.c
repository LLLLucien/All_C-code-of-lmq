#include <stdio.h>
int main()
{

    int i = 42;
    char c = 'C';
    double d = 3.1415;

    char *p1 = &c;
    int *p2 = &i;
    double *p3 = &d;

    void *p;

    printf("%lu %p\n", sizeof c, p1);
    printf("%lu %p\n", sizeof i, p2);
    printf("%lu %p\n", sizeof d, p3);
    return 0;
}