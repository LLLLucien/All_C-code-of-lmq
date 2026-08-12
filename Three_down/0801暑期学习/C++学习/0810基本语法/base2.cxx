// base2.cxx
//  引用和指针
#include <iostream>

int main(int argc, char const *argv[])
{
    // 指针
    int a = 42;
    int b = 2;
    int *p;  // 野指针
    p = &a;  // 赋值
    *p = 43; // 解引用
    p = &b;  // 指针再次赋值
    // 引用 & 标识r是一个引用
    // 相当于变量的别名
    // 声明时必须赋值，一旦赋值不可变
    int &r = a;
    std::cout << a << "," << r << std::endl;

    // 以往的值交换方法是利用指针
    void swap1(int *x, int *y);
    // 现在可用引用
    void swap2(int &x, int &y);
}