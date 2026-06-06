#include <stdio.h>
int main()
{
    double l, r, p;
    printf("Enter amount of loan: ");
    scanf("%lf", &l);
    printf("Enter interest rate: ");
    scanf("%lf", &r);
    r = r * 0.01 / 12;
    printf("Enter monthly payment: ");
    scanf("%lf", &p);
    double m1, m2, m3;
    m1 = l * r + l - p;
    l = m1;
    m2 = l * r + l - p;
    l = m2;
    m3 = l * r + l - p;
    printf("Balance remaining after first payment: $%.2f\n", m1);
    printf("Balance remaining after second payment: $%.2f\n", m2);
    printf("Balance remaining after third payment: $%.2f\n", m3);
}