#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *zi[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
char *unit[] = {"亿", "仟", "佰", "拾", "万", "仟", "佰", "拾", ""};

// 检查是否为纯数字
int is_all_digit(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// 去除前面的无效零
char *DeleteZore(char *str, int *new_len)
{
    int i = 0;
    while (i < strlen(str) && str[i] == '0')
        i++;
    if (i == strlen(str))
    {
        *new_len = 1;
        return "0";
    }
    *new_len = strlen(str) - i;
    // 返回的是第一个非零的地址
    return str + i;
}

int main()
{
    char m[20];
    printf("请输入一个非负整数(最大单位为亿,0~999999999):");
    fgets(m, sizeof(m), stdin);

    // 处理换行符
    int len = strlen(m);
    if (len > 0 && m[len - 1] == '\n')
    {
        m[len - 1] = '\0';
        len--;
    }

    // 校验
    if (len == 0 || len > 9 || !is_all_digit(m, len))
    {
        printf("输入错误:请输入0~999999999之间的纯数字整数！\n");
        return 0;
    }

    // 去除前面的零
    int new_len;
    char *num_str = DeleteZore(m, &new_len);
    if (new_len > 9)
    {
        printf("输入错误:数字超出范围！\n");
        return 0;
    }

    // 处理单个0的特殊情况
    if (new_len == 1 && num_str[0] == '0')
    {
        printf("整数 0 的汉字大写是:%s\n", zi[0]);
        return 0;
    }

    // 设计万/亿区间判断
    int has_wan = 0, has_yi = 0;
    for (int i = 0; i < new_len; i++)
    {
        int unit_idx = 9 - new_len + i;
        // 亿区间：unit_idx=0
        if (unit_idx == 0 && num_str[i] != '0')
            has_yi = 1;
        // 万区间：unit_idx=1~4
        if ((unit_idx >= 1 && unit_idx <= 4) && num_str[i] != '0')
            has_wan = 1;
    }

    // 输出原始数字+初始化标记
    printf("整数 %s 的汉字大写是:", num_str);
    int last_is_zero = 0, has_output = 0;
    int wan_output = 0; // 标记是否已输出万单位

    // 循环逐位处理
    for (int i = 0; i < new_len; i++)
    {
        char ch = num_str[i];
        int n = ch - '0';
        int unit_idx = 9 - new_len + i;

        // 情况1：当前位是零
        if (n == 0)
        {
            last_is_zero = 1;
            // 特殊：万位（unit_idx=4）且未输出过万 → 输出万
            if (unit_idx == 4 && has_wan && !wan_output)
            {
                printf("%s", unit[4]);
                wan_output = 1;
                last_is_zero = 0;
            }
            continue;
        }

        // 情况2：当前位非零 → 先输出累积的零
        if (last_is_zero == 1 && has_output)
        {
            printf("%s", zi[0]);
            last_is_zero = 0;
        }

        // 输出汉字+单位
        printf("%s", zi[n]);
        printf("%s", unit[unit_idx]);
        has_output = 1;

        // 标记万/亿已输出
        if (unit_idx == 4)
        {
            wan_output = 1;
            has_wan = 0;
        }
        if (unit_idx == 0)
            has_yi = 0;
    }

    printf("\n");
    return 0;
}