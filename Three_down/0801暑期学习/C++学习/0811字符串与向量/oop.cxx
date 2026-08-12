// oop.cxx
#include <iostream>
#include <string>

using namespace std;
// 访问修饰符：私有，公共，受保护
class Cat
{

    // 封装：保护内部状态以及实现细节
    // 1.
  private:
    string name;
    int *age;

  public:
    int getAge()
    {
        return *age;
    }
    void setAge(int n)
    {
        if (n > 0 && n < 20)
        {
            *age = n;
        }
    }
    // 重载：同名函数，参数不同
    Cat()
    {
    }
    // 构造函数：初始化对象的成员
    Cat(string s)
    {
        name = s;
        age = new int(0);
        cout << "Cat()构造函数 ~Cat析构函数\n";
    }
    // 析构函数：销毁对象的成员
    ~Cat()
    {
        delete age;
        cout << "~Cat析构函数\n";
    }
};

int main()
{
    // 创建了对象，会自动执行构造函数，程序结束自动执行析构函数
    Cat c1;
    // 如果是指针，需要分配内存空间才会自动执行构造函数
    Cat *c2 = new Cat();
    // 需要手动释放内存
    delete c2;
    c2 = nullptr;

    // 如果构造函数有参数，需要初始化的时候就要写参数
    // 否则会报错
    // 或者在类中多定义一个不带参数的，Cat(){}
    Cat c3("coco");

    return 0;
}
