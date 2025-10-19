#include <iostream>
using namespace std;

class Person
{
  public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(int age, int height)
    {
        mAge = age;
        mHeight = new int(height);
        cout << "Person的有参构造函数调用" << endl;
    }
    Person(const Person& p)
    {
        cout << "Person的拷贝构造函数调用" << endl;

        mAge = p.mAge;
        // mHeight = p.mHeight; //
        // 编译器默认实现上面这行代码，是浅拷贝，会导致p1和p2指向同一块内存地址，在后续delete的时候会两次访问内存

        mHeight = new int(*p.mHeight); // 手动实现深拷贝
    }
    ~Person()
    {
        if (mHeight != nullptr)
        {
            delete mHeight;
            mHeight = nullptr;
        }
        cout << "Person的析构函数调用" << endl;
    }

    int mAge;
    int* mHeight;
};

int main()
{
    Person p1(20, 180);
    Person p2(p1);

    cout << "p1的年龄：" << p1.mAge << "，身高：" << *p1.mHeight << endl;

    cout << "p2的年龄：" << p2.mAge << "，身高：" << *p2.mHeight << endl;

    return 0;
}