// Gof
#include <algorithm>
#include <iostream>

using namespace std;
class User
{
  public:
    // 静态属性：属于该类，而不是属于该类的对象

    static int count;
    int id;

    User()
    {
        cout << "User()" << endl;
        id = count++;
    }

    ~User()
    {
    }
    // 静态方法只能访问静态属性，不能访问非静态属性
    static void setCount(int n)
    {
        count = n;
        cout << "setCount" << endl;
    }
};
// 静态属性在类中声明，在类外初始化
int User::count = 0;

int main()
{

    User user1;

    cout << user1.id << endl;
    User user2;

    cout << user2.id << endl;
    User user3;

    User::setCount(100);
    cout << user3.id << endl;

    return 0;
}
