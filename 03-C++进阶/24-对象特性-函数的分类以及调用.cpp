#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person的无参构造函数被调用" << endl;
    }
    Person(int age)
    {
        m_Age = age;
        cout << "Person的有参构造函数被调用" << endl;
    }
    Person(const Person &p)
    {
        m_Age = p.m_Age;
        cout << "Person的拷贝构造函数被调用" << endl;
    }

    ~Person()
    {
        cout << "Person的析构函数被调用" << endl;
    }

    int m_Age;
};

int main()
{
    Person p1;
    Person p2(18);
    Person p3(p2);

    cout << "p2.m_Age = " << p2.m_Age << endl;
    cout << "p3.m_Age = " << p3.m_Age << endl;

    Person p4(); // 会被当成一个函数声明
    Person(20); // 匿名对象，会直接被释放
    // Person(p5); // 会被编译器解释为 Person p5;
    Person p5 = p3; // 会被编译器解释为 Person p5(p3);
    Person p6 = 10; // 会被编译器解释为 Person p6(10);

    cout << "p5.m_Age = " << p5.m_Age << endl;
    cout << "p6.m_Age = " << p6.m_Age << endl;

    return 0;
}