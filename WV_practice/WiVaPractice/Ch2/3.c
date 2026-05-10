/*改上题中的程序，使用户可以自行录入球体的半径*/
#include <stdio.h>
#define P 3.1415
int main()
{
    int R = 0;
    double V = 0;
    printf("Enter a R:");
    scanf("%d", &R);
    V = (4.0 / 3.0) * P * R * R * R;
    printf("V=%f\n", V);
    return 0;
}