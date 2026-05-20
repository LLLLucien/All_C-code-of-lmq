#include "Elevator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InputFloor(Request *Request)
{
    printf("请输入外部楼层请求");
    while (getchar() != '\n')
    {
        scanf("%d%c", &Request->floor, &Request->direction);
        Request->isProcessed = 0;
    }
}
void ElevatorRun(Request *Request)
{
    printf("电梯初始信息");
    printf("当前所在楼层：%d\n", Request->currentFloor);
    printf("最大载客数：%d\n", Request->maxPassenger);
    printf("当前载客数：%d\n", Request->currentPassenger);
    printf("当前运行状态：%d\n", Request->state);
}
