// Factory.cxx
// 工厂模式
// 静态工厂/简单工厂
#include <iostream>
#include <string>

using namespace std;
enum DocType
{
    WORD,
    ppt
};

// 例如一个文档父类
class Doc
{
  protected:
    string name;

  public:
    Doc(string name) : name(name)
    {
    }
    ~Doc()
    {
    }
    // 打开文档都是通过open
    void open()
    {
        cout << "open: " << name << endl;
    }
    // 编辑文档则需要子类实现
    virtual void edit() = 0;
};

class word : public Doc
{
    // private:
  public:
    word(string name) : Doc(name)
    {
    }
    void edit() override
    {
        cout << "edit word: " << name << endl;
    }
    ~word()
    {
    }
};

class PPT : public Doc
{
    // private:
  public:
    PPT(string name) : Doc(name)
    {
    }
    void edit() override
    {
        cout << "edit PPT: " << name << endl;
    }
    ~PPT()
    {
    }
};

// WPS 工厂类
class WPS
{
  public:
    WPS()
    {
    }
    ~WPS()
    {
    }
    // 通过工厂方法创建文档
    static Doc *create(DocType type, string name)
    {
        // 通过switch 来选择不同的文档类型
        // type 是需要整型
        switch (type)
        {
        case WORD:
            return new word(name);
        case ppt:
            return new PPT(name);
        default:
            return nullptr;
        }
    }
};
int main()
{

    Doc *doc;
    // 静态工厂方法创建文档
    doc = WPS::create(WORD, "word.doc");
    // 如果不用静态工厂方法创建文档,多了一个步骤
    // 就需要先 WPS wps;
    // doc = wps.create(WORD, "word.doc");
    doc->open();
    doc->edit();

    doc = WPS::create(ppt, "ppt.ppt");
    doc->open();
    doc->edit();

    return 0;
}