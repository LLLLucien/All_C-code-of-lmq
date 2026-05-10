/*写程序对表达式求值：*/
/*式中的操作数是浮点数，运算符是+ 、- 、* 和/ 。表达式
从左向右求值（所有运算符的优先级都一样）*/
#include <stdio.h>

double Result(double a, char c, double b)
{
    double sum = 0;
    if (c == '+')
    {
        sum = a + b;
    }
    else if (c == '-')
    {
        sum = a - b;
    }
    else if (c == '*')
    {
        sum = a * b;
    }
    else if (c == '/')
    {
        if (b == 0.0)
        {
            printf("错误：除数不能为0！\n");
            return 0.0;
        }
        sum = a / b;
    }
    else
    {
        printf("错误：非法运算符「%c」，仅支持+、-、*、/\n", c);
        return a; // 保留原有结果，不影响后续合法运算
    }

    return sum;
}

int main()
{
    double a, b, sum;

    char op;
    printf("输入一个表达式:");
    scanf("%lf", &a);
    sum = a;
    while (1)
    {
        // 2. 核心：用getchar读下一个字符（紧凑格式下，只能是「运算符」或「换行符」）
        op = getchar();
        // 3. 读到换行符/EOF，直接退出循环（彻底解决回车卡顿）
        if (op == '\n' || op == EOF)
        {
            break;
        }
        // 4. 紧凑格式下，读入的op就是纯运算符，直接读下一个紧凑浮点数
        scanf("%lf", &b);
        // 5. 调用函数计算，更新结果
        sum = Result(sum, op, b);
    }

    printf("结果为:%.2f\n", sum);
    return 0;
}