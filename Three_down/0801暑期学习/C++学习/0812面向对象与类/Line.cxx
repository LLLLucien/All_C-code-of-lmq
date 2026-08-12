// Line 类实现
#include "Line.h"

Line::Line(Point *s, Point *e)
    : start(s), end(e) // 指针成员：取实参的地址，指向实参本体（借用，不拥有）
{
    cout << "构造函数line\n" << endl;
}

Line::~Line()
{
    // Line 只"借用"外部点，不拥有它们，所以不 delete
    delete start;
    delete end;
    cout << "析构函数line\n" << endl;
}

Point Line::getStart()
{
    return *start; // 解引用：从指针拿到它指向的对象再返回
}

Point Line::getEnd()
{
    return *end; // 同理
}
void Line::setStart(int x, int y)
{
    start->setX(x); // 指针用 -> 访问成员
    start->setY(y);
}

void Line::setEnd(int x, int y)
{
    end->setX(x);
    end->setY(y);
}

void Line::showLine()
{
    cout << "线段：起点";
    start->showPoint();
    cout << "     终点";
    end->showPoint();
}