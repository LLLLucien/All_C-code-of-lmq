#include <stdio.h>
#include <string.h>

// 去除换行符，返回有效数字长度
int getlen(char *str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }
    return len; // 有效长度
}

// 反转字符串（大数值加法结果需要反转）
void TrueStr(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// 加法函数
void BigNumAdd(char *a, char *b, int *a_len, int *b_len, char *sum)
{
    int cin = 0;                                             // 进位标记
    int num1, num2;                                          // 临时存储每一位的数字
    int min_len = (*a_len) < (*b_len) ? (*a_len) : (*b_len); // 最小长度

    // 让a始终是更长的数组
    if (min_len == *a_len)
    {
        char temp[33] = {0}; // 临时数组存交换数据
        // 交换长度
        int temp_len = *a_len;
        *a_len = *b_len;
        *b_len = temp_len;
        // 交换数组内容
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }

    int j = 0; // 结果数组sum的下标
    // 处理两个数都有的位（min_len位）：从低位到高位
    for (int i = 0; i < min_len; i++)
    {
        num1 = a[*a_len - 1 - i] - '0'; // a的第i个低位
        num2 = b[*b_len - 1 - i] - '0'; // b的第i个低位

        int temp_sum = num1 + num2 + cin; // 求和，含上一轮进位
        sum[j] = (temp_sum % 10) + '0';   // 结果转字符
        cin = temp_sum / 10;              // 更新进位
        j++;
    }

    // 处理a中超出min_len的高位
    for (int i = min_len; i < *a_len; i++)
    {
        num1 = a[*a_len - 1 - i] - '0';
        int temp_sum = num1 + cin; // 高位仅加进位
        sum[j] = (temp_sum % 10) + '0';
        cin = temp_sum / 10;
        j++;
    }

    // 处理最后剩余的进位（比如999+1=1000）
    if (cin > 0)
    {
        sum[j] = cin + '0';
        j++;
    }
}

// 比较两个大数字符串的大小
// 返回值：1表示a >= b，0表示a < b
int CompareBigNum(char *a, int a_len, char *b, int b_len)
{
    // 长度不同：长度更长的数更大（和加法中"更长数组"逻辑一致）
    if (a_len > b_len)
        return 1;
    else if (a_len < b_len)
        return 0;
    // 长度相同：逐位比较
    else
    {
        for (int i = 0; i < a_len; i++)
        {
            if (a[i] > b[i])
                return 1;
            else if (a[i] < b[i])
                return 0;
        }
        // 所有位都相同：两数相等
        return 1;
    }
}

// 去除减法结果的前面的零
void RemoveLeadingZero(char *str)
{
    int len = strlen(str);
    int start = 0;
    // 找到第一个非零字符的位置
    while (start < len && str[start] == '0')
    {
        start++;
    }
    // 全零的情况（比如100-100=0）
    if (start == len)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    // 把非零部分移到字符串开头
    int j = 0;
    while (start < len)
    {
        str[j++] = str[start++];
    }
    str[j] = '\0';
}
// 减法函数
int BigNumSub(char *a, char *b, int *a_len, int *b_len, char *sum)
{
    int borrow = 0;                                          // 借位标记
    int num1, num2, diff;                                    // 临时存储每一位数字和差值
    int is_positive = 1;                                     // 结果是否为正（默认a>=b）
    int min_len = (*a_len) < (*b_len) ? (*a_len) : (*b_len); // 最小长度
    int j = 0;                                               // 结果数组res的下标

    // 比较a和b的大小，若a < b则交换（保证被减数≥减数，简化借位）
    if (!CompareBigNum(a, *a_len, b, *b_len))
    {
        is_positive = 0; // 结果为负
        // 交换a和b，以及长度
        char temp[33] = {0};
        int temp_len = *a_len;
        *a_len = *b_len;
        *b_len = temp_len;
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }

    // 处理两个数都有的位（min_len位）
    for (int i = 0; i < min_len; i++)
    {

        num1 = a[*a_len - 1 - i] - '0';
        num2 = b[*b_len - 1 - i] - '0';

        // 处理上一轮的借位,先减借位
        num1 -= borrow;
        borrow = 0; // 重置借位标记

        // 当前位不够减，需要借位
        if (num1 < num2)
        {
            num1 += 10; // 借1当10
            borrow = 1; // 标记借位，下一轮处理
        }

        // 计算差值，转字符存储
        diff = num1 - num2;
        sum[j++] = diff + '0';
    }

    // 处理a中超出min_len的高位
    for (int i = min_len; i < *a_len; i++)
    {
        num1 = a[*a_len - 1 - i] - '0';
        // 处理上一轮的借位）
        num1 -= borrow;
        borrow = 0;

        // 高位仍不够减
        if (num1 < 0)
        {
            num1 += 10;
            borrow = 1;
        }

        sum[j] = num1 + '0';
        j++;
    }

    // 步骤4：处理最后剩余的借位（加法处理剩余进位，减法处理剩余借位）
    // 注：减法的借位最终必须为0（因为已经保证a>=b），此处做容错
    if (borrow > 0)
    {
        sum[j++] = (10 - borrow) + '0';
    }

    // 步骤5：反转结果（和加法一样，逆序存储→正序）
    TrueStr(sum); // 复用你已有的反转函数

    // 步骤6：去除前导零（减法特有，加法无此问题）
    RemoveLeadingZero(sum);

    return is_positive; // 返回结果正负标记
}

int main()
{
    char a[33] = {0}; // 初始化避免乱码
    char b[33] = {0};
    char res[34] = {0}; // 结果数组（多1位存进位）
    int opt = 0;        // 0=加法，1=减法
    int a_len, b_len;   // 存储a/b的有效长度
    int is_positive;    // 减法结果的正负标记

    // 输入处理
    printf("输入两个数, 回车隔开(最大32位)\n");
    printf("输入第一个数：");
    fgets(a, sizeof(a), stdin);
    a_len = getlen(a);

    printf("\n输入第二个数：");
    fgets(b, sizeof(b), stdin);
    b_len = getlen(b);

    printf("\n进行加法还是减法？加法输入0，减法输入1：");
    scanf("%d", &opt);

    // 加法分支：调用封装的加法函数
    if (!opt)
    {
        // 核心：调用加法函数（传a_len/b_len的地址，因为函数内会交换）
        BigNumAdd(a, b, &a_len, &b_len, res);

        // 反转结果为正序
        TrueStr(res);

        // 输出结果
        printf("\n加法结果：%s\n", res);
    }
    else
    {
        char a_origin[33] = {0}, b_origin[33] = {0};
        strcpy(a_origin, a);
        strcpy(b_origin, b);

        is_positive = BigNumSub(a, b, &a_len, &b_len, res);
        // 输出减法结果（处理正负）
        printf("\n减法结果：");
        if (!is_positive)
            printf("-"); // 结果为负，加负号
        printf("%s\n", res);
    }

    return 0;
}