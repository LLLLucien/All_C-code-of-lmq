/*请修改4.1节的upc.c 程序以计算EAN的校验位。用户
把EAN的前12位当作一个数输入：*/
#include <stdio.h>
int main()
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12,
        first_sum, second_sum, total;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
          &i1, &i2, &i3, &i4, &i5, &i6,
          &i7, &i8, &i9, &i10, &i11, &i12);

    // 首先把第2位、第4位、第6位、第8位、第10位和第12位数字相加
    first_sum = i2 + i4 + i6 + i8 + i10 + i12;

    // 然后把第1 位、第3位、第5位、第7位、第9位和第11位数字相加
    second_sum = i1 + i3 + i5 + i7 + i9 + i11;
    // 接着把第一次加法的结果乘以3，再和第二次加法的结果相加

    total = 3 * first_sum + second_sum;
    // 随后，再把上述结果减去1；相减后的结果除以10取余数
    // 最后用9减去上一步骤中得到的余数

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
    return 0;
}