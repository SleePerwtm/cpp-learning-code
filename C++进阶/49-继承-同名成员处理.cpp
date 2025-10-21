#include <iostream>

class Base {
  public:
    int mA;
    Base() { mA = 1; }
    void func() { std::cout << "Base::func()" << std::endl; }
    void func(int a) { std::cout << "Base::func(int)" << std::endl; }
};

class Derived : public Base {
  public:
    int mA;
    Derived() { mA = 2; }
    void func() { std::cout << "Derived::func()" << std::endl; }
};

// 同名成员，直接访问的是子类中的，前面加上作用域限定符Base::是访问父类的成员
void test1() {
    Derived d;
    std::cout << "d.mA = " << d.mA << std::endl;
    std::cout << "d.Base::mA = " << d.Base::mA << std::endl;
}

// 成员函数同理
void test2() {
    Derived d;
    d.func();
    d.Base::func();
    // d.func(1); //
    // 子类存在同名函数，会将父类所有同名函数隐藏，因此显示子类该函数不存在
    // 若想调用父类的同名函数，需要加上作用域限定符Base::
    d.Base::func(1);
}

int main() {
    test1();
    test2();
}