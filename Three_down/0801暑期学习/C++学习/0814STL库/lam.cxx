// lam.cxx
// lambda 表达式

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // // lambda 表达式
    // // [] 捕获列表 []无传入，[&]可修改，[=] 只读
    // // () 参数列表
    // // -> 返回类型
    // // {} 函数体
    // auto lambda = [](int a, int b) -> int { return a + b; };

    // auto f = []() { cout << "hello world" << endl; };

    // f(); // 调用 lambda 表达式

    // int a = 10;
    // int b = 20;
    // //  加了= 表示捕获列表，会把 a 和 b 拷贝到 lambda 表达式中，但不可修改
    // auto f1 = [=]() { cout << a << "," << b << endl; };
    // // & 表示引用，会把 a 和 b 的引用拷贝到 lambda 表达式中，可以修改
    // auto f2 = [&]() { cout << a << "," << b << endl; };

    // f1();

    // auto f3 = [&](int x, int y) -> int
    // {
    //     a *= 10;
    //     b *= 10;
    //     x += a;
    //     y += b;
    //     return x + y;
    // };

    // cout << f3(1, 2) << endl;
    // cout << a << endl;
    // cout << b << endl;

    // vector<int> v = {42, 31, 1, 78, 6};
    // sort(v.begin(), v.end());
    // // 第三个参数是一个比较器（comparator），它决定了排序的规则
    // // "什么样的 x应该排在 y 前面
    // sort(v.begin(), v.end(), [](int x, int y) { return x > y; });
    // for (auto &&i : v)
    // {
    //     cout << i << ",";
    // }
    // // 挨个遍历，同时能换行
    // for_each(v.begin(), v.end(), [](int n) { cout << n << endl; });

    // 返回得到满足条件的第一个
    // auto it = find_if(v.begin(), v.end(), [](int x) { return x > 30; });

    // 打印所有符合条件的
    // while (it != v.end())
    // {
    //     cout << *it << endl;
    //     it = find_if(it + 1, v.end(), [](int x) { return x > 30; });
    // }

    return 0;
}