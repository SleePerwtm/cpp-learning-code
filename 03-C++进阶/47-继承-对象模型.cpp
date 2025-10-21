#include <iostream>

class Base {
  public:
    int mA;
    int mB;

  private:
    int mC;
};

class Derived : public Base {
  public:
    int mD;
};

// 大小应为16而不是12，将私有成员也包含进去了
// 父类的所有非静态成员属性都会被子类继承，包括私有成员属性
// 父类的私有成员属性被编译器隐藏，因此子类无法访问，但确实被继承了
void printSizeOfClass() {
    Derived obj;
    std::cout << "Size of Derived class: " << sizeof(obj) << std::endl;
}

// 使用Visual Studio的开发人员命令提示符，能查看对象模型
// 切换到项目路径
// 查看命令：
// cl /d1 reportSingleClassLayout<类名> <文件名>
//
// 如查看 Derived 类的布局：
// cl /d1 reportSingleClassLayoutDerived 47-继承-对象模型.cpp
//
// 输出：
// 47-继承-对象模型.cpp

// class Derived   size(16):
//         +---
//  0      | +--- (base class Base)
//  0      | | mA
//  4      | | mB
//  8      | | mC
//         | +---
// 12      | mD
//         +---

int main() { printSizeOfClass(); }