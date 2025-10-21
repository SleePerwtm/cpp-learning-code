#include <iostream>

class Base {
  public:
    Base() { std::cout << "Base 的构造函数调用" << std::endl; }
    ~Base() { std::cout << "Base 的析构函数调用" << std::endl; }
};

class Derived : public Base {
  public:
    Derived() { std::cout << "Derived 的构造函数调用" << std::endl; }
    ~Derived() { std::cout << "Derived 的析构函数调用" << std::endl; }
};

// 先调用 Base 的构造函数，再调用 Derived 的构造函数
void test1() { Derived d; }
// 先调用 Derived 的析构函数，再调用 Base 的析构函数

int main() { test1(); }