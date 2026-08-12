#include "Point.h"

// ========== Point 类实现 ==========

Point::Point()
{
    x = 0;
    y = 0;
    cout << "构造函数Point\n" << endl;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
    cout << "构造函数Point\n" << endl;
}

Point::Point(int n)
{
    x = n;
    y = n;
    cout << "构造函数Point\n" << endl;
}

Point::~Point()
{
    cout << "析构函数Point\n" << endl;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}
void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

void Point::showPoint()
{
    cout << "(" << x << ", " << y << ")" << endl;
}
