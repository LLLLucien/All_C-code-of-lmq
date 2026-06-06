
#define PI 3.1415
#define C(r) 2 * PI *(r) // 参数需要扩起来
#define MUL(a, b) (a) * (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
// 把a当字符串处理
#define STR(a) #a
#define TO_STR(a) STR(a)
// 把a，b拼起来
#define CAT(a, b) a##b
// 函数重载
// C中不可以用相同名，不同类型
// 不过可以用宏
int my_max(int, int);
int my_min(int, int);