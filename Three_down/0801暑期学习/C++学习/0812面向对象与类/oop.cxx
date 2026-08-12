#include <iostream>

using namespace std;

class A
{
  private:
    // 外部无法直接访问
    int pri_a;

  protected:
    // 外部无法访问，但子类可访问
    int pro_a;

  public:
    // 外部可以直接访问
    int pub_a;

    A() : pri_a(0), pro_a(0), pub_a(0)
    {
        cout << "A()" << endl;
    }
    A(int a, int b, int c) : pri_a(a), pro_a(b), pub_a(c)
    {
        cout << " A(int a,int b,int c)" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
    void show()
    {
        cout << "A =" << pri_a << endl;
        cout << "A =" << pro_a << endl;
        cout << "A =" << pub_a << endl;
    }
};
class B : public A
{
  private:
  public:
    B()
    {
        cout << "B()" << endl;
    }
    B(int a, int b, int c, int d)
    {

        cout << "B()" << endl;
    }
    ~B()
    {
        cout << "~B()" << endl;
    }
};
int main()
{

    B b;
    // 直接使用了A的show，而且变量也是A的
    b.show();
    // 输出结果
    // A()
    // B()
    // A =0
    // A =0
    // A =0
    // ~B()
    // ~A()
    return 0;
}
