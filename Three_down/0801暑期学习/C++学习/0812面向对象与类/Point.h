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
    void setX(int x);
    void setY(int x);
    void showPoint();
};
