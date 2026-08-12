#include <iostream>
#include <string>
// 至少有一个纯虚函数的类，叫做抽象类
// 抽象类不能实例化，用来用于继承

using namespace std;
class Shape
{
  private:
  protected:
    string name;

  public:
    Shape() : name("Shape")
    {
        cout << "Shape()" << endl;
    }
    virtual ~Shape()
    {
        cout << "~Shape()" << endl;
    }
    // 纯虚函数
    virtual double Area() = 0;
    void show()
    {
        cout << "name: " << name << endl;
    }
};

class Circle : public Shape
{
  private:
  public:
    Circle()
    {
        name = "Circle";
        cout << "Circle()" << endl;
    }
    ~Circle()
    {
        cout << "~Circle()" << endl;
    }
    // 重写纯虚函数,才能创建实例
    double Area() override
    {
        cout << "Circle::Area()" << endl;
        return 0;
    }
};

class Triangle : public Shape
{
  private:
  public:
    Triangle()
    {
        name = "Triangle";
        cout << "Triangle()" << endl;
    }
    ~Triangle()
    {
        cout << "~Triangle()" << endl;
    }
    double Area() override
    {
        cout << "Triangle::Area()" << endl;
        return 0;
    }
};

int main()
{
    Shape *s1;
    s1 = new Circle();
    s1->show();
    s1->Area();
    delete s1;

    s1 = new Triangle();
    s1->show();
    s1->Area();
    delete s1;
    return 0;
}