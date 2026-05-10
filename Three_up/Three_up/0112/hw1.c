// 3.使用1-9的数字，构造三个三位数a，b，c
// b = a * 2 c = a * 3 数字不能重复
//1-9累加和以及乘机
#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c;
    // 用于标记数字1-9是否被使用过，初始化为0（未使用）
    int used[10];

    // a的范围：三位数，且a*3也必须是三位数 → a ≤ 333
    for (a = 100; a <= 333; a++)
    {
        b = a * 2;
        c = a * 3;

        // 确保b和c都是三位数
        if (b > 999 || c > 999)
            continue;

        // 每次检查前重置标记数组
        memset(used, 0, sizeof(used));

        // 提取a的每一位数字并检查
        int digit1 = a / 100;                             // 百位
        int digit2 = (a / 10) % 10;                       // 十位
        int digit3 = a % 10;                              // 个位
        if (digit1 == 0 || digit2 == 0 || digit3 == 0 ||  // 不能有0
            used[digit1] || used[digit2] || used[digit3]) // 不能重复
            continue;
        used[digit1] = used[digit2] = used[digit3] = 1;

        int digit4 = b / 100;
        int digit5 = (b / 10) % 10;
        int digit6 = b % 10;
        if (digit4 == 0 || digit5 == 0 || digit6 == 0 ||
            used[digit4] || used[digit5] || used[digit6])
            continue;
        used[digit4] = used[digit5] = used[digit6] = 1;

        int digit7 = c / 100;
        int digit8 = (c / 10) % 10;
        int digit9 = c % 10;
        if (digit7 == 0 || digit8 == 0 || digit9 == 0 ||
            used[digit7] || used[digit8] || used[digit9])
            continue;

        printf("a = %d, b = %d, c = %d\n", a, b, c);
    }

    return 0;
}