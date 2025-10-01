#include <iostream>
using namespace std;

/*
 * 1、创建一个类的时候，编译器会自动添加至少三个函数
 * - 默认构造函数——空实现
 * - 默认析构函数——空实现
 * - 拷贝构造函数——默认实现，复制所有成员变量
 */

/*
 * 2、
 * - 如果我们写了有参构造函数，编译器就不会再提供默认构造函数，依然提供默认拷贝构造
 * - 如果写了拷贝构造函数，编译器就不会再提供其他普通构造
 */

class Person1
{
  public:
    Person1()
    {
        cout << "Person1的默认构造函数被调用" << endl;
    }
    Person1(int age)
    {
        cout << "Person1的构造函数被调用" << endl;
        mAge = age;
    }

    /*拷贝构造函数默认为复制所有成员变量*/

    // Person1(const Person1& p)
    // {
    //     cout << "Person1的拷贝构造函数被调用" << endl;
    //     mAge = p.mAge;
    // }
    ~Person1()
    {
        cout << "Person1的析构函数被调用" << endl;
    }

    int mAge;
};

void test1()
{
    Person1 p1(20);
    Person1 p2(p1); // 会调用默认拷贝构造函数，复制所有成员变量

    cout << "p2.mAge = " << p2.mAge << endl;
}

class Person2
{
  public:
    // 定义了有参构造函数，则编译器不会再提供默认无参构造函数
    Person2(int age)
    {
        cout << "Person2的构造函数被调用" << endl;
        mAge = age;
    }
    ~Person2()
    {
        cout << "Person2的析构函数被调用" << endl;
    }

    int mAge;
};

void test2()
{
    // Person2 p1; // 定义了有参构造函数，则编译器不会再提供默认无参构造函数
    Person2 p2(20);
    Person2 p3(p2);

    cout << "p3.mAge = " << p3.mAge << endl;
}

class Person3
{
  public:
    Person3(int age)
    {
        cout << "Person3的有参构造函数被调用" << endl;
        mAge = age;
    }
    Person3(const Person3& p)
    {
        cout << "Person3的拷贝构造函数被调用" << endl;
        mAge = p.mAge;
    }
    ~Person3()
    {
        cout << "Person3的析构函数被调用" << endl;
    }

    int mAge;
};

void test3()
{
    // Person3 p1;     // 定义了拷贝构造函数，则编译器不会再提供默认构造函数
    Person3 p2(20); // 定义了拷贝构造函数，则编译器不会再提供有参构造函数
    Person3 p3(p2); // 会调用自定义拷贝构造函数，复制所有成员变量

    cout << "p3.mAge = " << p3.mAge << endl;
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

    return 0;
}