// oop.cxx
// 菱形继承
#include <iostream>

class A
{
  public:
    int n;
    A(int n) : n(n)
    {
        std::cout << "A" << std::endl;
    }
    ~A()
    {
        std::cout << "~A" << std::endl;
    }
    void show()
    {
        std::cout << "n: " << n << std::endl;
    }
};

// class X : public A
// {
//   public:
//     X(int n) : A(n)
//     {
//         std::cout << "X" << std::endl;
//     }
//     ~X()
//     {
//         std::cout << "~X" << std::endl;
//     }
// };
class X : virtual public A
{
  public:
    X(int n) : A(n)
    {
        std::cout << "X" << std::endl;
    }
    ~X()
    {
        std::cout << "~X" << std::endl;
    }
};

class Y : virtual public A
{
  public:
    Y(int n) : A(n)
    {
        std::cout << "Y" << std::endl;
    }
    ~Y()
    {
        std::cout << "~Y" << std::endl;
    }
};

class Z : public X, public Y
{
  public:
    Z(int n, int m) : X(n), Y(m)
    {
        std::cout << "Z" << std::endl;
    }
    ~Z()
    {
        std::cout << "~Z" << std::endl;
    }
};
int main()
{
    Z z(10, 5);
    // 此时z的n是从哪个基类继承过来的？
    z.show();
    // 加上虚继承即可使用
    return 0;
}