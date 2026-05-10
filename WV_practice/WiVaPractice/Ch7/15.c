/*计算正整数的阶乘*/
#include <stdio.h>
#include <limits.h> // 提供整数类型的最大值（如 SHRT_MAX、INT_MAX）
#include <math.h>   // 提供 isinf 函数（判断浮点数是否为无穷大）

int main()
{
    // --------------------------
    // (a) short 类型
    // --------------------------
    printf("(a) short 类型:\n");
    short fact_short = 1;
    int n_short = 1;
    while (1)
    {
        // 预判溢出：如果当前值 > 最大值/(n+1)，则下一次乘法会溢出
        if (fact_short > SHRT_MAX / (n_short + 1))
            break;
        n_short++;
        fact_short *= n_short;
    }
    printf("最大可正确计算的 n = %d, 阶乘值 = %hd\n", n_short, fact_short);

    // --------------------------
    // (b) int 类型
    // --------------------------
    printf("\n(b) int 类型:\n");
    int fact_int = 1;
    int n_int = 1;
    while (1)
    {
        if (fact_int > INT_MAX / (n_int + 1))
            break;
        n_int++;
        fact_int *= n_int;
    }
    printf("最大可正确计算的 n = %d, 阶乘值 = %d\n", n_int, fact_int);

    // --------------------------
    // (c) long 类型
    // --------------------------
    printf("\n(c) long 类型:\n");
    long fact_long = 1;
    int n_long = 1;
    while (1)
    {
        if (fact_long > LONG_MAX / (n_long + 1))
            break;
        n_long++;
        fact_long *= n_long;
    }
    printf("最大可正确计算的 n = %d, 阶乘值 = %ld\n", n_long, fact_long);

    // --------------------------
    // (d) long long 类型（现代编译器都支持）
    // --------------------------
    printf("\n(d) long long 类型:\n");
    long long fact_llong = 1;
    int n_llong = 1;
    while (1)
    {
        if (fact_llong > LLONG_MAX / (n_llong + 1))
            break;
        n_llong++;
        fact_llong *= n_llong;
    }
    printf("最大可正确计算的 n = %d, 阶乘值 = %lld\n", n_llong, fact_llong);

    // --------------------------
    // (e) float 类型（近似值）
    // --------------------------
    printf("\n(e) float 类型:\n");
    float fact_float = 1.0f;
    int n_float = 1;
    while (1)
    {
        float next = fact_float * (n_float + 1);
        // 浮点数溢出为无穷大，或精度丢失（乘后值不变）时停止
        if (isinf(next) || next == fact_float)
            break;
        n_float++;
        fact_float = next;
    }
    printf("最大可正确计算的 n = %d, 阶乘（近似值）= %f\n", n_float, fact_float);

    // --------------------------
    // (f) double 类型（近似值）
    // --------------------------
    printf("\n(f) double 类型:\n");
    double fact_double = 1.0;
    int n_double = 1;
    while (1)
    {
        double next = fact_double * (n_double + 1);
        if (isinf(next) || next == fact_double)
            break;
        n_double++;
        fact_double = next;
    }
    printf("最大可正确计算的 n = %d, 阶乘（近似值）= %f\n", n_double, fact_double);

    // --------------------------
    // (g) long double 类型（近似值）
    // --------------------------
    printf("\n(g) long double 类型:\n");
    long double fact_ldouble = 1.0L;
    int n_ldouble = 1;
    while (1)
    {
        long double next = fact_ldouble * (n_ldouble + 1);
        if (isinf(next) || next == fact_ldouble)
            break;
        n_ldouble++;
        fact_ldouble = next;
    }
    printf("最大可正确计算的 n = %d, 阶乘（近似值）= %Lf\n", n_ldouble, fact_ldouble);

    return 0;
}