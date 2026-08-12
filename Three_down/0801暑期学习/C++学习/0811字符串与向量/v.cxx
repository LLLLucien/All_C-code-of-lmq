#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // 容器，模板类型
    vector<int> v1;                 // size=0
    vector<int> v2(10);             // size=10，10个0
    vector<int> v3(10, 1);          // size=10，10个1
    vector<int> v4{10, 1};          // size=2，含有10和1
    vector<string> v5(10, "hello"); // 存了10个hello,size=10

    for (auto &&i : v5)
    {
        cout << i << ",";
    }
    cout << v5.size() << "," << endl;

    v1.reserve(17); // 分配17个空间
    cout << v1.size() << "," << v1.capacity() << endl;
    for (int i = 0; i < 17; i++)
    {
        // 从末尾插入
        v1.push_back(i);
        cout << v1.size() << "," << v1.capacity() << endl;
    }
    // 删除末尾元素，不过没有返回值
    v1.pop_back();

    vector<int> v6 = {100, 200, 300};
    // 取得第一个
    v6.front();
    // 取得最后一个
    v6.back();
    // 变为数组指针形式
    int *p = v6.data();

    vector<int> v7;
    // 相当于拷贝v6给v7
    v7 = v6;

    // 获得迭代器
    // 相当于一个指针，获得第一个位置
    auto it = v6.begin();
    v6.insert(it, 666);
    // 利用迭代器遍历
    for (auto i = v6.begin(); i != v6.end(); i++)
    {
    }
}