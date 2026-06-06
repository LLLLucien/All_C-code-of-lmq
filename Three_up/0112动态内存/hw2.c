#include <stdio.h>
#include <stdlib.h>

// 返回字符指针
char *int_to_hex(int num)
{
    // 函数内部定义十六进制字符映射，替代全局变量
    const char hex_chars[] = "0123456789ABCDEF";
    // 临时数组存储余数（最多需要8位十六进制数 + 终止符，足够处理int范围的非负整数）
    int remainders[16];
    int count = 0; // 记录余数的个数
    int temp = num;

    // 处理num=0的特殊情况
    if (num == 0)
    {
        // 分配内存存储 "0" + 终止符，长度为2
        char *hex_str = (char *)malloc(3 * sizeof(char));
        if (hex_str == NULL)
        { // 内存分配失败处理
            perror("内存分配失败");
            exit(EXIT_FAILURE);
        }
        hex_str[0] = '0';
        hex_str[1] = 'x';
        hex_str[2] = '0';
        hex_str[3] = '\0'; // 终止符
        return hex_str;
    }

    // 循环取余，收集十六进制位（低位在前）
    while (temp > 0)
    {
        remainders[count++] = temp % 16;
        temp = temp / 16;
    }

    // 分配内存："0x" + 十六进制位数 + 终止符
    char *hex_str = (char *)malloc((count + 3) * sizeof(char)); // 0x + count位 + \0
    if (hex_str == NULL)
    {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }

    // 拼接十六进制字符串（带0x前缀）
    hex_str[0] = '0';
    hex_str[1] = 'x';
    int str_index = 2; // 从第3位开始填充十六进制字符（0x之后）
    // 倒序填充（因为余数是低位在前，需要转成高位在前）
    for (int i = count - 1; i >= 0; i--)
    {
        hex_str[str_index++] = hex_chars[remainders[i]];
    }
    hex_str[str_index] = '\0'; // 字符串终止符

    return hex_str;
}

int main()
{
    int num = 0;
    int t;                   // 接收scanf返回值，判断输入有效性
    char *hex_result = NULL; // 存储转换后的十六进制字符串

    while (1)
    {
        printf("输入任意字母结束循环，请输入一个非负整数: ");
        t = scanf("%d", &num);

        // 处理非数字输入
        if (t != 1)
        {
            printf("检测到非数字输入，程序停止！\n");
            break;
        }
        // 处理负数输入
        if (num < 0)
        {
            printf("请输入一个正确的非负整数！\n");
            continue;
        }

        // 调用转换函数，获取十六进制字符串
        hex_result = int_to_hex(num);
        // 输出结果
        printf("整数 %d 的十六进制是: %s\n", num, hex_result);

        // 释放函数返回的动态内存，避免内存泄漏
        free(hex_result);
        hex_result = NULL; // 置空防止野指针
    }

    return 0;
}