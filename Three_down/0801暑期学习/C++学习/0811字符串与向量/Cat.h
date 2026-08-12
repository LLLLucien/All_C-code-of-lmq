// Cat.h
#include <iostream>
#include <string>

using namespace std;
class Cat
{
  private:
    string name;
    int age;

  public:
    Cat();
    Cat(string name);
    ~Cat();
    string getName();
    int getAge();
    void setAge(int n);
    void show();
};