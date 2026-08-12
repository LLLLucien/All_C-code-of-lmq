#include <iostream>

// 自定义命名空间

namespace xyz
{
    int n = {9};

    void hello()
    {
        std::cout << "hello A\n";
    }
} // namespace xyz

// 相同的会合并，同时也可以嵌套
namespace xyz
{
    int m = {9};

    void cout()
    {
        std::cout << "hello A\n";
    }
} // namespace xyz

// 在当前作用域找不到某个名字时，顺便去 xyz 命名空间里也找一找
// using namespace xyz;

// 可以单独using命名空间的某一个
using xyz::hello;

// 在C中 定义一个类型
typedef unsigned long int id;
// C ++ 中
using id = unsigned long int;

int main(int argc, char const *argv[])
{
    std::cout << "n:" << xyz::n << std::endl;
    hello();

    // 动态分配内存
    // 在C中
    // int *p = (int *)malloc(sizeof(int));
    // *p = 42;
    // free(p);
    // p = NULL;
    // 在C++中先分配再初始化
    int *p1 = new int;
    std::cout << p1 << "," << *p1 << std::endl;

    *p1 = 42;
    std::cout << p1 << "," << *p1 << std::endl;
    // 分配空间的同时初始化
    int *p2 = new int(42);
    // 释放空间
    delete p1; // 销毁
    std::cout << p1 << "," << *p1 << std::endl;
    p1 = nullptr; // 赋值为空
    std::cout << p1 << "," << std::endl;
}
