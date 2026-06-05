// pri.c
// fprintf、sprintf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // sprintf
    char text[128];
    char *name = "bob";
    char *tel = "13800000000";
    int age = 18;

    // 把内容输入到一个特定的字符串中
    // 相当于字符串的拼接
    sprintf(text, "姓名：%s,电话：%s,年龄：%d", name, tel, age);
    // fprintf
    //  格式化输出到文件
    FILE *fp = fopen("a.csv", "w");
    fprintf(fp, "%s，%d\n", "alice", 18);
    fprintf(fp, "%s，%d\n", "bob", 19);
    fprintf(fp, "%s，%d\n", "jack", 20);
    // 直接输出到标准输出
    fprintf(stdout, "%s，%d\n", "rose", 21);
    fclose(fp);

    return 0;
}
// 1