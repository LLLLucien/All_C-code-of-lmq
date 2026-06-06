// 循环
// loop.c
#include <stdio.h>
int main()
{
    //-------------break,continue
    for (int i = 0; i < 9; i++)
    {
        if (i == 5)
            continue;
        printf("%d,", i);
    }
    //-------------for()
    /*
    for (int i = 0; i < 9; i += 2)
    {
        printf("hello %d\n", i);
    }
    */
    //-------------do-while
    /*
    char ch;
    do
    {
        printf("...\n");
        printf("输入 y 继续，输入 n 退出:");
        // 接收一个字符，输入一个字节+回车
        // scanf("%c", &ch);
        ch = getchar();
        getchar(); // 处理缓冲区
    } while (ch == 'y');
    printf("the end\n");
*/
    //-------------while
    /*
    int n;
    printf("输入一个整数：");
    scanf("%d", &n);
    int sum = 0;

    while (n > 0)
    {
        sum += (n % 10); // 345=>5
        n /= 10;         // 345=>34
    }
    printf("累加和%d\n", sum);
    */
    //-------------纸张折叠
    /*
    float h = 0.0001; // 1mm
    float m = 8848;   // 8848m

    int count = 0; // 计数器

    while (h < m)
    {
        h *= 2;
        count++;
    }
    printf("需要折叠%d次,此时纸张厚度为%fm", count, h);
    */
    return 0;
}