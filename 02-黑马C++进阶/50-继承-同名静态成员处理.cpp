#include <iostream>

class Base {
  public:
    static int sA;
};

class Derived : public Base {
  public:
    static int sA;
};

int Base::sA = 1;
int Derived::sA = 2;

// 与同名非静态成员处理方式相同
void test1() {
    Derived d;
    std::cout << "通过对象调用静态成员:" << std::endl;
    std::cout << "sA in Derived: " << d.sA << std::endl;
    std::cout << "sA in Base: " << d.Base::sA << std::endl;
}

void test2() {
    Derived d;
    std::cout << "通过类名调用静态成员:" << std::endl;
    std::cout << "sA in Derived: " << Derived::sA << std::endl;
    std::cout << "sA in Base: " << Derived::Base::sA << std::endl;
}

int main() {
    test1();
    test2();
}