#include <stdio.h>
int main()
{
    // 转义字符 '\'
    // char s1 = '\0';
    // char s2[] = "中";

    char s1[] = {'a', 'b', 'c'};
    // 字符串“”括住的文本内容，空间大小是元素大小加一
    char s2[] = "abc";                                 // 大小是4，因为会默认加一个分割‘\0’
    char s3[] = {'a', 'b', 'c', '\0'};                 // 与上面的“abc”是一样的
    char s4[] = {'a', 'b', 'c', '\0', 'x', 'y', '\0'}; // 只会打印前三个abc
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    // putchar与getchar
    // char ch1, ch2;
    // printf("请输入一个字符：");
    // // 从标准输入stdin读取一个字符
    // // getchar调用的仍然是grtc
    // ch1 = getchar();
    // ch2 = getc(stdin);
    // // 向标准输出stdout写出一个字符
    // putchar(ch1);
    // putc(ch2, stdout);

    // 区分数值表示和字符表示
    //  char ch1 = 1;   // 字符1
    //  char ch2 = '1'; // 数值1
    //  char ch3 = 'a';
    //  printf("数值：%d,符号：'%c'\n", ch1, ch1);
    //  printf("数值：%d,符号：'%c'\n", ch2, ch2);
    //  11111111 = 256个 = 数值最大255
    //  char 1字节 有符号 0~127与-1 ~ -128
    //  for (int i = 0; i < 128; i++)
    //  {
    //      printf("'%c' (%-3d)\t", i, i);
    //      if (i % 8 == 7)
    //      {
    //          printf("\n");
    //      }
    //  }

    // 判断是否是数字、字母
    // char ch;
    // printf("请输入一个字符：");
    // scanf("%c", &ch);
    // if (ch >= '0' && ch <= '9')
    // {
    //     printf("这是数字\n");
    // }
    // // 也可以用正则表达式（模式匹配）
    // if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    // {
    //     printf("这是字母\n");
    // }

    return 0;
}