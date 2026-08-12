// 2. 燃油、电力（新能源） 车：油车、电车、混合动力 摩托：油车、电车

#include <iostream>
#include <string>

using namespace std;
class Vehicle
{
  public:
    virtual void run() = 0;
    virtual void energy_type() = 0;
    virtual void show() = 0;
    // 多态基类必须有虚析构函数：
    // 否则通过 Vehicle* delete 派生类对象时，只会调用 ~Vehicle()，
    // 派生类析构函数被跳过，导致资源泄漏
    virtual ~Vehicle()
    {
        cout << "Vehicle析构函数" << endl;
    };
};

class Car : public Vehicle
{
  public:
    void run() override
    {
        cout << "车在行驶" << endl;
    }
    void show() override
    {
        cout << "这是车" << endl;
    }
    ~Car()
    {
        cout << "Car析构函数" << endl;
    };
};

class ElectricCar : public Car
{
  public:
    void energy_type() override
    {
        cout << "能源: 电力" << endl;
    }
    void show() override
    {
        cout << "这是电车" << endl;
    }
    ~ElectricCar()
    {
        cout << "ElectricCar析构函数" << endl;
    }
};
class Motorcycle : public Vehicle
{
  public:
    void run() override
    {
        cout << "摩托在行驶" << endl;
    }
    void show() override
    {
        cout << "这是摩托" << endl;
    }
    ~Motorcycle()
    {
        cout << "Motorcycle析构函数" << endl;
    }
};
class ElectricMotorcycle : public Motorcycle
{
  public:
    void energy_type() override
    {
        cout << "能源: 电力" << endl;
    }
    void show() override
    {
        cout << "这是电摩托" << endl;
    }
    ~ElectricMotorcycle()
    {
        cout << "ElectricMotorcycle析构函数" << endl;
    }
};
class FuelMotorcycle : public Motorcycle
{
  public:
    void energy_type() override
    {
        cout << "能源: 燃油" << endl;
    }
    void show() override
    {
        cout << "这是油摩托" << endl;
    }
    ~FuelMotorcycle()
    {
        cout << "FuelMotorcycle析构函数" << endl;
    }
};
class HybridCar : public Car
{
  public:
    void energy_type() override
    {
        cout << "能源: 燃油+电力" << endl;
    }
    void show() override
    {
        cout << "这是混合动力车" << endl;
    }
    ~HybridCar()
    {
        cout << "HybridCar析构函数" << endl;
    }
};
class FuelCar : public Car
{
  public:
    void energy_type() override
    {
        cout << "能源: 燃油" << endl;
    }
    void show() override
    {
        cout << "这是油车" << endl;
    }
    ~FuelCar()
    {
        cout << "FuelCar析构函数" << endl;
    }
};

int main()
{

    Vehicle *v[] = {new ElectricCar, new FuelCar, new HybridCar,
                    new ElectricMotorcycle, new FuelMotorcycle};

    for (int i = 0; i < 5; i++)
    {
        cout << "--------------------" << endl;
        v[i]->show(); // 运行时按实际类型分发
        v[i]->run();
        v[i]->energy_type();
        cout << "--------------------" << endl;
        delete v[i];
    }
    return 0;
}