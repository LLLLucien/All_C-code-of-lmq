#ifndef ELEVATOR_H
#define ELEVATOR_H

typedef enum {
    UP,     // 上行
    DOWN,   // 下行
    STOP,   // 停止
    FAULT   // 故障
} ElevatorState;

typedef struct {
   
   int floor;              // 请求所在楼层（外部请求楼层）
    int targetFloor;        // 目标楼层（乘客内部目标，批量预输入）
    int passengerCount;     // 该请求的乘客数量（默认1人，可扩展批量输入）
    int direction;          // 请求方向（UP/DOWN，仅外部请求必填）
    int isProcessed;        // 是否已接人处理（0-未接，1-已接）
} Request;

typedef struct {
  int currentFloor;       // 当前所在楼层
    int maxPassenger;       // 最大载客数（固定为5）
    int currentPassenger;   // 当前载客数
    ElevatorState state;    // 当前运行状态
    int targetFloors[10];   // 目标楼层队列（存储需要停靠的楼层）
    int targetDirections[10]; // 对应每个目标楼层的停靠方向（UP/DOWN）
    int targetCount;        // 目标楼层数量
    int stopSequence[50];   // 最终停靠序列存储
    int stopCount;          // 停靠次数
} Elevator;
#endif