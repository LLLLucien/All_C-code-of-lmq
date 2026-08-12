#include <iostream>

using namespace std;

class Point
{
  private:
    int x;
    int y;

  public:
    Point();
    Point(int x, int y);
    Point(int x);
    ~Point();
    int getX();
    int getY();
    void showPoint();
};

class Line
{
  private:
    Point start; // 起点
    Point end;   // 终点

  public:
    Line();
    Line(Point s, Point e);
    ~Line();
    Point getStart();
    Point getEnd();
    void showLine();
};
