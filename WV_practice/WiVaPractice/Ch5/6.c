/*修改4.1节的upc.c 程序，使其可以检测UPC的有效性。在用户
输入UPC后，程序将显示VALID 或NOT VALID*/
#include <stdio.h>
int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, L1, L2,
        first_sum, second_sum, total;

    printf("Enter the first 12 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
          &d, &i1, &i2, &i3, &i4, &i5,
          &j1, &j2, &j3, &j4, &j5, &L1);

    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    L2 = 9 - ((total - 1) % 10);
    printf("Check digit: %d\n", L2);
    if (L2 != L1)
        printf("NOT VALID\n");
    else
        printf("VALID\n");

    return 0;
}