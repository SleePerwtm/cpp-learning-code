#include <iostream>
using namespace std;

class Person
{
  public:
    Person()
    {
        cout << "Person的默认构造函数被调用" << endl;
    }
    Person(int age)
    {
        mAge = age;
        cout << "Person的构造函数被调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数被调用" << endl;
    }
    Person(const Person& p)
    {
        mAge = p.mAge;
        cout << "Person的拷贝构造函数被调用" << endl;
    }

    int mAge;
};

// 1、使用一个已经创建完毕的对象来初始化一个新对象
void test1()
{
    Person p1(20);
    Person p2(p1);
}

// 2、值传递的方式给函数传值
void doWork(Person p)
{
}
void test2()
{
    Person p;
    doWork(p);
}

// 3、值方式返回局部对象
Person doWork2()
{
    Person p1(20);
    cout << &p1 << endl;
    return p1;
}
void test3()
{
    Person p =
        doWork2(); // 理论上来讲会在这里调用拷贝构造函数，但实际上编译器进行了优化，延长了doWork2中p1的生命周期，省去了不必要的拷贝构造函数调用
    cout << &p << endl; // p的地址和p1的地址相同，说明没有调用拷贝构造函数，p1的生命周期被延长
}

int main()
{
    cout << "test1():" << endl;
    test1();
    cout << endl;

    cout << "test2():" << endl;
    test2();
    cout << endl;

    cout << "test3():" << endl;
    test3();
    cout << endl;

    return 0;
}