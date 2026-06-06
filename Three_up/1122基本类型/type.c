// type.c
// 基本类型
/**
 * @author lmq@123123
 * @date 2025/11/22
 *
 *
 *
 */
#include <stdio.h>

int main()
{
    // sizeof()获得类型或者变量在内存中占用的空间大小
    // printf() 参数一：字符串模板,使用shift + alt + 下 可以复制
    // ctrl + alt + 下 可以多行编辑
    //% 占位符，%d 格式化输出整数，%ld格式输出long int
    printf("大小：%ld\n", sizeof(char));        // 1
    printf("大小：%ld\n", sizeof(short));       // 2
    printf("大小：%ld\n", sizeof(int));         // 4
    printf("大小：%ld\n", sizeof(long));        // 8
    printf("大小：%ld\n", sizeof(long long));   // 8
    printf("大小：%ld\n", sizeof(float));       // 4
    printf("大小：%ld\n", sizeof(double));      // 8
    printf("大小：%ld\n", sizeof(long double)); // 16
    printf("大小：%ld\n", sizeof(_Bool));       // 1
    return 0;
}
