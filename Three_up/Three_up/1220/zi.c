#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int main()
{
    setlocale(LC_ALL, "zh_CN.UTF-8");

    // 1. 基础定义：数字大写、单位（仅用wchar_t数组，无字符串/指针）
    wchar_t num_char[] = {L'零', L'壹', L'贰', L'叁', L'肆', L'伍', L'陆', L'柒', L'捌', L'玖'};
    wchar_t unit_char[] = {L'仟', L'佰', L'拾', L'亿'}; // 4位数的单位：千、百、十、个（个位无单位）
    wchar_t big_unit[] = {L'亿', L'万'};                // 亿级、万级的大单位

    // 2. 输入处理
    int num;
    wprintf(L"输入金额（0~%d）：", INT_MAX);
    scanf("%d", &num);

    if (num < 0 || num > INT_MAX)
    {
        wprintf(L"金额超出范围！\n");
        return 1;
    }
    if (num == 0)
    {
        wprintf(L"零\n");
        return 0;
    }

    // 3. 拆分：直接拆出亿、万、个级的4位数（无逆序数组，逻辑极简）
    int yi = num / 100000000 % 10000; // 亿级：0~9999
    int wan = num / 10000 % 10000;    // 万级：0~9999
    int ge = num % 10000;             // 个级：0~9999

    // 4. 核心状态变量（仅保留3个，极简）
    int last_zero = 0;            // 0=上一个不是零，1=上一个是零（防组内重复零）
    int yi_has_non = (yi != 0);   // 亿级是否有非零
    int wan_has_non = (wan != 0); // 万级是否有非零
    int ge_has_non = (ge != 0);   // 个级是否有非零

    // 5. 通用处理单级4位数的逻辑（循环+选择，无高阶语法）
    // 输入：4位数val、是否输出大单位（如万/亿）、大单位字符
    auto process_level = [&](int val, int print_big_unit, wchar_t big_u)
    {
        if (val == 0)
            return; // 无数字则跳过

        int level_last_zero = 0; // 本级内的零标记（避免和全局last_zero混淆）
        int val_copy = val;
        // 遍历4位：千(1000)→百(100)→十(10)→个(1)
        for (int i = 0; i < 4; i++)
        {
            int divisor = 1;
            // 计算当前位的除数（千=1000，百=100，十=10，个=1）
            for (int j = 0; j < 3 - i; j++)
                divisor *= 10;
            int digit = val_copy / divisor; // 当前位数字（0-9）
            val_copy = val_copy % divisor;  // 剩余数字

            if (digit == 0)
            {
                // 组内零：仅当后续有非零、且本级内上一个不是零，才输出零
                if (!level_last_zero && val_copy != 0)
                {
                    wprintf(L"%lc", num_char[0]);
                    level_last_zero = 1;
                    last_zero = 1; // 更新全局零标记
                }
                continue;
            }
            // 输出数字+单位（个位无单位）
            wprintf(L"%lc", num_char[digit]);
            if (unit_char[i] != L'')
            {
                wprintf(L"%lc", unit_char[i]);
            }
            level_last_zero = 0;
            last_zero = 0; // 更新全局零标记
        }

        // 输出大单位（亿/万）
        if (print_big_unit)
        {
            wprintf(L"%lc", big_u);
            last_zero = 0; // 输出大单位后，重置零标记
        }
    };

    // 6. 按「亿→万→个」顺序处理（核心逻辑）
    // 处理亿级
    process_level(yi, 1, big_unit[0]);

    // 亿→万 跨级零判断：亿有非零、万有非零、且万级开头是零，补零
    if (yi_has_non && wan_has_non)
    {
        int wan_first_zero = (wan / 1000 == 0); // 万级开头（千位）是零
        if (wan_first_zero && last_zero)
        {
            wprintf(L"%lc", num_char[0]);
            last_zero = 1;
        }
    }

    // 处理万级
    process_level(wan, 1, big_unit[1]);

    // 万→个 跨级零判断：万有非零、个有非零、且个级开头是零，补零
    if (wan_has_non && ge_has_non)
    {
        int ge_first_zero = (ge / 1000 == 0); // 个级开头（千位）是零
        if (ge_first_zero && last_zero)
        {
            wprintf(L"%lc", num_char[0]);
            last_zero = 1;
        }
    }

    // 处理个级（无大单位）
    process_level(ge, 0, L'');

    wprintf(L"\n");
    return 0;
}