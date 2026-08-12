// str.cxx
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s1;           // 长度为0的空字符串
    string s2 = "hello"; // 相当于拷贝了该字面量hello给s2
    string s3("world");  // 这个才是初始化
    string s4(6, 'a');   // 初始化了6个a

    // 给字符串s1赋值，但读取到空格或换行结束
    // cin >> s1;
    // 读取一行给s1赋值

    while (getline(cin, s1))
    {
        // 不再是传字符串作为参数，而是使用字符串带有的函数
        // 判断是否是空字符串
        if (s1.empty())
            break;
        cout << s1 << endl;

        // 取得大小，自动得到类型
        auto len = s1.size();
        cout << "size:" << len << endl;
    }

    // 字符串拼接
    cout << s2 + " 123" + s3 << endl;
    string s5 = s2 + "0 000" + s3;
    cout << s5 << endl;
    // 其他拼接方法
    string s7 = "cpp";
    s7.append("okok");
    // 但无法拼接字面量
    // string s6 = "hello" + "world";

    // 比较字符
    string s8 = "abcddd";
    string s9 = "dacdds";
    if (s8 == s9)
    {
        cout << "相同" << endl;
    }
    // 遍历字符串
    string s10 = "hello";
    for (size_t i = 0; i < s10.size(); i++)
    {
        // 这个不会进行月结判断
        cout << s10[i] << endl;
        // at 会做越界判断
        cout << s10.at(i) << endl;
    }
    // c++有的新的遍历方法
    // 取s10里每一个拷贝给r
    for (auto r : s10)
    {
        r++;
    }

    // r是每个字符的引用，如果修改r，则原件也会被修改
    for (auto &r : s10)
    {
        r -= 32;
    }

    // 和auto r一样，不可修改，但性能更好
    for (const auto &r : s10)
    {
    }
    // 万能引用，可以修改，临时变量
    for (auto &&r : s10)
    {
    }
    auto &w = s1;
    auto &t = w;
    auto &g = t;

    cout << s3 << endl;
    cout << s4 << endl;
}