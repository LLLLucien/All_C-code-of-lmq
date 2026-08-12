// base.cxx
#include <iostream>
// Input Stream/Output Stream
// cout,cin
// 命名空间 std::cout,std::cin
// g++ base.cxx -o base
// 在正式工程中，推荐使用命名空间std::cout,std::cin

using namespace std;

int main(int argc, char *argv[])
{

    // int a;
    // double b;
    // // scanf("%d %d",&a,&b);
    // std::cin >> a >> b;
    // std::cout << "a=" << a << ",b=" << b << std::endl;
    // std::cout << "a+b=" << a + b << std::endl;
    int val = 0;
    int sum = 0;
    std::cout << "please input:\n";
    while (std::cin >> val)
    {
        sum += val;
    }
    std::cout << "sum:" << sum << "\n";

    // 变量初始化
    int a = 1;
    int b = {1}; // 列表初始化 能够提示错误
    int d{1};    // 列表初始化 能够提示错误
    int c(1);    // 构造函数初始化

    int g{b};    // 窄化类型
    auto v3 = a; // 会进行类型的自动推导
    return 0;
}