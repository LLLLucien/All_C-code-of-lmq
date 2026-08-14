// stl.cxx
// 双向循环链表

#include <iostream>
// 有序容器
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

// 容器适配器
#include <queue>
#include <stack>

// 有序关联容器
// 红黑树实现
// 红黑树是一个二叉搜索树
// 1. 每个节点都用红色或黑色标记
// 2. 根节点是黑色
// 3. 每个叶子节点的外部节点是黑色
// 4. 如果一个节点是红色，则它的子节点必须是黑色
// 5. 从任一节点到其每个叶子节点的所有路径都包含相同数目的黑色节点
#include <map>
#include <set>

// 无序关联容器
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    // 初始化一个空的list
    // list<int> l1;
    // // 插入元素
    // l1.push_back(1);
    // l1.push_front(2);
    // // 指定位置插入元素，在链表头部（第一个元素之前）插入
    // l1.insert(l1.begin(), 1);
    // for (auto &&i : l1)
    // {
    //     cout << i << endl;
    // }

    // deque 双端队列
    // 分块存储、块内连续存储、用块索引指针数组
    // 支持随机访问，性能比vector差
    // 支持双端插入
    // 扩容：不移动或拷贝数据，只移动指针
    //   deque<int> d1;
    // d1.push_back(1);
    // d1.push_back(2);
    // d1.push_back(3);
    // d1.push_front(9);
    // d1.push_front(10);
    // d1.push_front(11);
    // d1.insert(d1.begin() + 1, 12);
    // d1.at(1);
    // d1[1];
    // for (auto &&i : d1)
    // {
    //     cout << i << endl;
    // }
    // cout << d1.at(1) << endl;
    // cout << d1[1] << endl;

    // deque 容器适配器

    // stack 栈基于deque实现
    // stack<int> s1;
    // s1.push(1);
    // s1.push(2);
    // while (!s1.empty())
    // {
    //     cout << s1.top() << endl;
    //     s1.pop();
    // }

    // queue 队列也是基于deque实现
    // queue<int> q1;
    // q1.push(1);
    // q1.push(2);
    // q1.push(3);
    // q1.push(4);
    // while (!q1.empty())
    // {
    //     cout << q1.front() << endl;
    //     cout << q1.back() << endl;
    //     q1.pop();
    // }

    // priority_queue 优先队列
    // priority_queue<int> q2;
    // q2.push(87);
    // q2.push(2);
    // q2.push(34);
    // q2.push(54);
    // q2.push(5);
    // q2.push(16);
    // while (!q2.empty())
    // {
    //     cout << q2.top() << endl;
    //     q2.pop();
    // }

    // 有序关联容器
    // 无重复set 集合
    // 有重复的set multiset
    // set<int> s1;
    // s1.insert(1);
    // s1.insert(2);
    // s1.insert(42);
    // s1.insert(7);
    // s1.insert(56);
    // // 无法随机访问s1[1]
    // for (auto &&i : s1)
    // {
    //     cout << i << endl;
    // }

    // // 无重复map 字典
    // map<string, int> m1;
    // // 不同的方式插入元素
    // m1.insert({"one", 1});
    // m1["two"] = 2;
    // m1["three"] = 3;
    // m1["four"] = 4;
    // // 查找元素
    // cout << m1["one"] << endl;
    // cout << m1["two"] << endl;
    // for (auto &&i : m1)
    // {
    //     cout << i.first << i.second << endl;
    // }

    // // 有重复的map multimap
    // // 无法使用[]访问元素
    // multimap<string, int> m1;
    // m1.insert({"one", 1});

    // 无序关联容器
}
