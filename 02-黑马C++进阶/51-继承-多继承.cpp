#include <iostream>

// 语法
// class DerivedClass : public Base1, public Base2, public Base3 {...};
// 多继承时父类中可能有同名成员存在，需要加作用域区分

// 多继承的示例
class Base1 {
  public:
    int mA;
    Base1() { mA = 10; }
};

class Base2 {
  public:
    int mB;
    Base2() { mB = 20; }
};

class Derived1 : public Base1, public Base2 {};

void test1() {
    Derived1 d;
    std::cout << "mA = " << d.mA << std::endl;
    std::cout << "mB = " << d.mB << std::endl;
}

// 多继承可能由于父类存在同名成员而冲突
class Base3 {
  public:
    int mC;
    Base3() { mC = 30; }
};

class Base4 {
  public:
    int mC;
    Base4() { mC = 40; }
};

class Derived2 : public Base3, public Base4 {};

void test2() {
    Derived2 d;
    std::cout << "Base3::mC = " << d.Base3::mC
              << std::endl; // 需要用作用域来区分
    std::cout << "Base4::mC = " << d.Base4::mC << std::endl;
}

int main() {
    test1();
    test2();
}