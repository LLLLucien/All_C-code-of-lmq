// Factory2.cxx
// 抽象工厂模式
#include <iostream>
#include <string>

using namespace std;

class PC
{
  public:
    PC()
    {
    }
    ~PC()
    {
    }
    virtual void show() = 0;
};
class Phone
{
  public:
    Phone()
    {
    }
    ~Phone()
    {
    }
    virtual void show() = 0;
};

class MI : public Phone
{
  public:
    void show() override
    {
        cout << "MI" << endl;
    }
};

class IPhone : public Phone
{
  public:
    void show() override
    {
        cout << "IPhone" << endl;
    }
};

class MiBook : public PC
{
  public:
    void show() override
    {
        cout << "MiBook" << endl;
    }
};
class Mac : public PC
{
  public:
    void show() override
    {
        cout << "Mac" << endl;
    }
};
class Factory
{

  public:
    virtual PC *createPC() = 0;
    virtual Phone *createPhone() = 0;
};

class FactoryMI : public Factory
{
  public:
    PC *createPC() override
    {
        return new MiBook();
    }
    Phone *createPhone() override
    {
        return new MI();
    }
};
class FactoryApple : public Factory
{
  public:
    PC *createPC() override
    {
        return new Mac();
    }
    Phone *createPhone() override
    {
        return new IPhone();
    }
};

int main()
{
    // 用户只面对抽象工厂接口，具体选哪家由这里决定
    Factory *f = new FactoryApple; // 换成 FactoryMI 整套就换品牌

    PC *pc = f->createPC();          // 拿到苹果电脑
    Phone *phone = f->createPhone(); // 拿到苹果手机

    pc->show();    // 输出：苹果电脑
    phone->show(); // 输出：苹果手机

    return 0;
}