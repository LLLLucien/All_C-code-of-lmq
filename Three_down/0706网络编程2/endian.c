// 大端小端验证
#include <stdio.h>

int main()
{
    // 四个字节
    int n = 0x12345678;
    // p指向n的第一个字节
    char *p = (char *)&n;
    //%x 十六进制输出,%#x 十六进制输出，带0x
    // 小端
    printf("%p,%#x\n", p, *p); // 0x78
    p++;
    printf("%p,%#x\n", p, *p); // 0x56
    p++;
    printf("%p,%#x\n", p, *p); // 0x34
    p++;
    printf("%p,%#x\n", p, *p); // 0x12
    return 0;
}