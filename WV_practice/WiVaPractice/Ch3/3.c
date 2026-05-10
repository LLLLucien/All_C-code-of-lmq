/*书用国际标准书号（ISBN）进行标识。2007年1月1日之后分
配的ISBN包含13位数字（旧的ISBN使用10位数字），分为5组，如978-
0-393-97950-3。第一组（GS1前缀 ）目前为978或979。第二组（组
标识 ）指明语言或者原出版国（如0和1用于讲英语的国家）。第三
组（出版商编号 ）表示出版商（393是W. W. Norton出版社的编
号）。第四组（产品编号 ）是由出版商分配的用于识别具体哪一本
书的（97950）。ISBN的末尾是一个校验数字 ，用于验证前面数字的
准确性。编写一个程序来分解用户录入的ISBN信息：*/
#include <stdio.h>
int main()
{
    int n1, n2, n3, n4, n5;
    printf("Enter ISBN(x-x-x-x-x):");
    scanf("%d-%d-%d-%d-%d", &n1, &n2, &n3, &n4, &n5);

    printf("GS1 prefix: %d\n", n1);
    printf("Group identifier: %d\n", n2);
    printf("Publisher code: %d\n", n3);
    printf("Item number: %d\n", n4);
    printf("Check digit: %d\n", n5);
    return 0;
}