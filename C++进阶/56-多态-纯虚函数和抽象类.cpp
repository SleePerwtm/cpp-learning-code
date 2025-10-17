#include <iostream>
using namespace std;

class Base {
  public:
    virtual void printInfo() = 0; // 定义纯虚函数
}; // 拥有纯虚函数的类是抽象类

// 虽然这是纯虚函数，但是其也可以有实现
void Base::printInfo() { cout << "This is a Base class object." << endl; }

class Derived : public Base {
  public:
    void printInfo() { cout << "This is a Derived class object." << endl; }
};

void test() {
    // Base b; // 抽象类不能实例化
    Derived d;
    Base* p = &d;
    p->printInfo(); // 调用虚函数，调用的是派生类的实现
}

int main() { test(); }