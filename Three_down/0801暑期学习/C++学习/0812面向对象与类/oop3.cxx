// oop3.cxx
#include <iostream>

// 特殊的抽象类：接口类
// 1.所有函数都是纯虚函数
// 2.没有数据成员

class USB
{
  public:
    virtual ~USB() = default;
    // = 0 表示接口类，不实现
    virtual void plugIn() = 0;
    virtual void plugOut() = 0;
    virtual void run() = 0;
};

class MP3 : public USB
{
  private:
  public:
    MP3()
    {
        std::cout << "MP3 构造" << std::endl;
    };
    ~MP3()
    {
        std::cout << "MP3 析构" << std::endl;
    };
    void plugIn() override
    {
        std::cout << "MP3 插入" << std::endl;
    };
    void plugOut() override
    {
        std::cout << "MP3 拔出" << std::endl;
    };
    void run() override
    {
        std::cout << "MP3 正在播放" << std::endl;
    };
};

int main()
{
    MP3 mp3;
    mp3.plugIn();
    mp3.run();
    mp3.plugOut();
    return 0;
}