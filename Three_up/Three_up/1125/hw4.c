#include <stdio.h>
int main()
{
    double m;
    printf("Enter an amount:");
    scanf("%lf", &m);
    m += m * 0.05;
    printf("With tax added:$%.2f\n", m);
}