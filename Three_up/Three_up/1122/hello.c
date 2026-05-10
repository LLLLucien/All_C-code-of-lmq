#include <stdio.h> //standard input output
// gcc hello.c
// 生成了a.out，a表示汇编，out表示输出
// gcc hello.c -o hello才能生成特定文件

// 汇编：gcc -S hello.c（生成hello.s）
// 编译：gcc -c hello.s（c表示编译，生成hello.o）
// 链接：gcc hello.o -o hello（生成执行文件，hello）
// 执行：./hello
int main()
{
    int d = 0;
    scanf("%d", &d);
    d += 1;
    printf("%d\n", d);
    return 0; // 返回给OS的状态码，0表示正常结束
}