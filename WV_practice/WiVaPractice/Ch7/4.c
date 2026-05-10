/*写程序可以把字母格式的电话号码翻译成数值格式,果没有电话在身边，参考这里给出的字母在键盘上的对应关
系：2=ABC ，3=DEF ，4=GHI ，5=JKL ，6=MNO ，7=PQRS ，
8=TUV ，9=WXYZ 。）原始电话号码中的非字母字符（例如数字或
标点符号）保持不变：假设任何用户输入的字母都是大写字母。
*/
/*  1    2=ABC  3=DEF ，
  4=GHI  5=JKL  6=MNO ，
  7=PQRS 8=TUV  9=WXYZ*/
#include <stdio.h>
int main()
{
    char n;
    int m;
    printf("\t====请输入电话号码====\n");
    printf("(1)     \t(2)=ABC\t\t(3)=DEF\t\n");
    printf("(4)=GHI \t(5)=JKL\t\t(6)=MNO\t\n");
    printf("(7)=PQRS\t(8)=TUV\t\t(9)=WXYZ\t\n");
    while (1)
    {
        scanf("%c", &n);
        if (n == '\n')
            break;
        else if (n >= 'A' && n <= 'C')
            printf("2");
        else if (n >= 'D' && n <= 'F')
            printf("3");
        else if (n >= 'G' && n <= 'I')
            printf("4");
        else if (n >= 'J' && n <= 'L')
            printf("5");
        else if (n >= 'M' && n <= 'O')
            printf("6");
        else if (n >= 'P' && n <= 'S') // P-S：7
            printf("7");
        else if (n >= 'T' && n <= 'V') // T-V：8
            printf("8");
        else if (n >= 'W' && n <= 'Z') // W-Z：9
            printf("9");
        else // 非字母直接输出
            printf("%c", n);
    }

    printf("\n");
    return 0;
}