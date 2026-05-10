/*写一个程序，提示用户以(xxx) xxx-xxxx的格式输入电话号
码，并以xxx.xxx.xxxx的格式显示该号码*/
#include <stdio.h>
int main()
{
    int n1, n2, n3;
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &n1, &n2, &n3);
    printf("You entered:%d.%d.%d\n", n1, n2, n3);
    return 0;
}