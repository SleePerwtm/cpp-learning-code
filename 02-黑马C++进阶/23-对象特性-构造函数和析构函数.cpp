#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person的构造函数被调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数被调用" << endl;
    }
};

int main()
{
    cout << "程序开始" << endl;
    Person p;
    cout << "程序结束" << endl;
    return 0;
}