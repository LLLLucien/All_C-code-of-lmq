#include "Point.h"
#include <iostream>
using namespace std;

class Line
{
  private:
    Point *start; // 起点（指针成员：指向外部对象，借用不拥有）
    Point *end;   // 终点

  public:
    Line(Point *s, Point *e);
    ~Line();
    Point getStart();
    Point getEnd();
    void setStart(int x, int y);
    void setEnd(int x, int y);
    void showLine();
};
