// 测试Cat.h和Cat.cxx
// main.cxx
#include "Cat.h"

int main()
{
    Cat c1;
    Cat c2("汪汪");
    // c1.setAge(10);
    c2.setAge(2);
    c1.show();
    c2.show();
}