#include <stdio.h>

union U
{
    char a;
    short b;
    int c;
};

int main()
{
    union U u1;
    u1.a = 'x';
    u1.b = 30000;
    u1.c = 80000;
    return 0;
}