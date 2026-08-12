#include "Point.h"

// ========== Point 类实现 ==========

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(int n)
{
    x = n;
    y = n;
}

Point::~Point()
{
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::showPoint()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

// Line 类实现

Line::Line() : start(), end() // 使用初始化列表，调用 Point 的默认构造
{
}

Line::Line(Point s, Point e) : start(s), end(e) // 用传入的点初始化两个端点
{
}

Line::~Line()
{
}

Point Line::getStart()
{
    return start; // 返回整个 Point 对象，它自带 x 和 y
}

Point Line::getEnd()
{
    return end; // 同理
}

void Line::showLine()
{
    cout << "线段：起点";
    start.showPoint();
    cout << "     终点";
    end.showPoint();
}