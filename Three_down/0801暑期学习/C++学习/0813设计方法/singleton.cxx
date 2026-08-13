// singleton.cxx
#include <iostream>

using namespace std;
/*
单例模式 = 三个环节配合：
1. 构造函数私有 → 外部想创建对象？没门，只有这一条路可走
2. static 成员函数 → 没有对象也能调用这个入口（类名::getInstance()）
3. 函数内的静态局部变量 → 这个入口被调用一万次，instance 也只构造一次
*/

// 懒汉式:第一次调用getInstance时才创建对象
class Singleton1
{
  private:
    int x;
    int y;
    // 1. 构造函数私有化
    Singleton1(int a)
    {
        x = a;
    }

  public:
    // 2. 提供一个静态的公有函数，返回实例对象的指针
    // 一般叫getInstance
    static Singleton1 *getInstance(int a)
    {
        // 3.创建一个静态的实例对象，如果这个对象已经被创建，则不会再创建
        static Singleton1 instance(a);
        return &instance;
    }
    void foo()
    {
        cout << "x = " << x << endl;
    }
    ~Singleton1()
    {
    }
};

// 饿汉式：提前创建对象
class Singleton2
{
  private:
    Singleton2()
    {
        cout << "Singleton2()" << endl;
    }

  public:
    static Singleton2 instance;

    static Singleton2 *getInstance()
    {
        return &instance;
    }
};
// 提前创建对象，即使没有调用getInstance，也会创建对象
Singleton2 Singleton2::instance;

int main()
{
    // 4. 通过公有函数获取实例对象的指针
    Singleton1 *s1 = Singleton1::getInstance(3);
    s1->foo();
    // 5. 以后再创建都是同一个对象，所以4不会传入
    Singleton1 *s2 = Singleton1::getInstance(4);
    s2->foo();
    return 0;
}