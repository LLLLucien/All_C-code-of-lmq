/*- 1.定义一个命名空间 my
  - 基于new/delete实现一个动态数组 my::array
  - 数组长度可变
*/
#include <cstring>
#include <iostream>

namespace my
{

    struct Array
    {
        int *data;    // 数据指针
        int capacity; // 容量（最多能存几个）
        int count;    // 当前元素个数

        // 初始化
        void Init()
        {
            capacity = 3;
            count = 0;
            data = new int[capacity];
        }

        // 释放内存
        void Free()
        {
            delete[] data;
        }

        // 添加数据
        void Push(int x)
        {
            if (count >= capacity)
            {
                capacity *= 2; // 翻倍扩容
                int *temp = new int[capacity];
                memcpy(temp, data, count * sizeof(int));
                delete[] data;
                data = temp;
            }
            data[count++] = x;
        }

        int Get(int index)
        {
            return data[index];
        }

        int getSize()
        {
            return count;
        }
        int getspace()
        {
            return capacity;
        }
    };

} // namespace my

using namespace std;

int main(int argc, char const *argv[])
{
    my::Array arr1;
    arr1.Init();
    cout << "插入一个数\n";
    arr1.Push(1);
    cout << "插入一个数\n";
    arr1.Push(2);
    cout << "插入一个数\n";
    cout << "当前数组大小：" << arr1.getspace() << endl;
    cout << "当前元素数量：" << arr1.getSize() << endl;
    arr1.Push(3);
    cout << "插入一个数\n";
    cout << "当前数组大小：" << arr1.getspace() << endl;
    cout << "当前元素数量：" << arr1.getSize() << endl;
    arr1.Push(3);
    cout << "插入一个数\n";
    cout << "当前数组大小：" << arr1.getspace() << endl;
    cout << "当前元素数量：" << arr1.getSize() << endl;
    cout << "得到第0个数" << arr1.Get(0) << endl;
    cout << "得到第一个数" << arr1.Get(1) << endl;
    arr1.Free();
    return 0;
}