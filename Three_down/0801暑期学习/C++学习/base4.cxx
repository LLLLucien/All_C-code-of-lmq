// base4.cxx
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    // 数组的基本形式
    // 方法一
    int *p = new int[3];
    p[0] = 100;
    p[1] = 100;
    p[2] = 100;
    // 方法二
    int *p2 = new int[3]{100, 200, 300};

    // 动态数组
    // 方法一
    int *p3 = new int[5];
    for (int i = 0; i < 3; i++)
    {
        p3[i] = p2[i];
    }
    // 方法二
    //  导入#include <cstring>
    int *p4 = new int[6];
    // 拷贝p的东西给p4
    memcpy(p4, p, sizeof(int) * 3);

    // 释放
    delete[] p;
    p = p2;
    p2 = nullptr;
}