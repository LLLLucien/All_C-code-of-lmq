#include <stdio.h>
int main()
{
    // int *p = NULL;
    // int a = 42;
    // printf("%p\n", p);
    // p = &a;
    // if (p != NULL)
    // {
    //     printf("%d\n", *p);
    // }
    // return 0;

    int ch[9] = {0};
    int *p = NULL;
    *p = ch;
    // 与下面的相等
    //*p=&ch;
    //*p=&ch[0];
}