// Cat.cxx
#include "Cat.h"

Cat::Cat()
{
    cout << "构造函数1\n";
    name = "猫猫";
    age = 1;
}
Cat::Cat(string name)
{
    cout << "构造函数2\n";
    // name默认是参数变量，成员变量需要用this
    this->name = name;
}
// 其他方法
// Cat::Cat(string s):name(s)
int Cat::getAge()
{
    return age;
}
void Cat::setAge(int n)
{
    if (n > 0 && n < 20)
    {
        age = n;
    }
}
string Cat::getName()
{
    return name;
}
void Cat::show()
{
    cout << "name=" << name << endl;
    cout << "age=" << age << endl;
}
Cat::~Cat()
{

    cout << "析构函数\n";
};