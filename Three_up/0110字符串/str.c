// str.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    // scanf("%s", m);      // 读取到空格就不读了
    // gets(m);             // 读取到换行就不读了
    char m[16];
    fgets(m, 15, stdin); // 标准输入读取15个字符，写到m里面

    // 字符指针数组
    char *zi[] = {"零", "壹", "贰"}; // 一个汉字多个字节，所以用“”,可以用字符指针

    int len = strlen(m) - 1;
    for (int i = 0; i < len; i++)
    {
        char ch = m[i];
        int n = ch - '0'; // 可将字符转为数值
        printf("%s\n", zi[n]);
    }

    /*-----------------------------------------
    // strtok 拆分字符token
    char s1[] = "alice,jack,rose:tom";
    // 1.目标字符串 2.分隔符
    char *tok = strtok(s1, ",:"); // 返回的是第一个token的地址

    while (tok != NULL)
    {
        printf("%s\n", tok);
        // 1.参数NULL
        // 后续调用：NULL表示继续处理上一个字符串，分隔符保持和第一次一致
        tok = strtok(NULL, ",:");
        // 会修改原来的字符串，所以最好先复制备份
    }
    */
    /*--------------------------------------------
    // strstr 子串查找
    // strcasestr 忽略大小写的查找
    char s1[] = "hello";
    char s2[] = "java";
    char *p = strstr(s1, "lo");
    if (p == NULL)
    {
        printf("没有找到\n");
    }
    else
    {
        printf("index=%ld\n", p - s1); // 可以找到子串的第一个下标
    }
    */
    /*----------------------------------------------------------
    char s1[] = "javascript";
    char s2[] = "java";

    int r = strcmp(s1, s2); // 逐个字符比较，相同为0，不同为相减的值
    printf("%d\n", r);

    char *p = strchr(s1, 'v'); // 找到的返回的是指针
    // strrchr是从最后开始匹配

    if (p == NULL) // 可以直接 if(!p)
    {
        printf("没有找到\n");
    }
    else
    {
        printf("找到了\n");
        printf("%ld\n", p - s1);//可以输入下标

        printf("%s\n", p);
    }
    */
    /*----------------------------------------
    char s1[] = "hello"; // 方法一：由于要拼接s2，所以至少需要9个空间
    // char s1[9] = "hello";
    char s2[] = "C++";

    int size = strlen(s1) + strlen(s2) + 1;

    char s3[size];
    strcpy(s3, s1); // 先进行覆盖
    // printf("%lu\n", sizeof(s3));

    strcat(s3, s2); // 再进行追加、拼接
    // printf("%lu\n", sizeof(s3));

    printf("%s\n", s3);
    strncpy(s1, "welcome", sizeof(s1) - 1);
    printf("%s\n", s1);
    */
    //---------------------------------------
    return 0;
}