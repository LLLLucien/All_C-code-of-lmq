#include "Line.h"

int main()
{
    // Point a(1, 1);
    Point *a = new Point(1, 1);
    // Point b(2, 2);
    Point *b = new Point(1, 1);

    a->showPoint();
    b->showPoint();

    Line p1(a, b);
    p1.showLine();
    // p1.setStart(2, 2);
    a->setX(9);
    a->setY(8);
    a->showPoint();
    p1.showLine();

    // delete a; // main new 的，由 main delete
    // delete b;
    return 0;
}