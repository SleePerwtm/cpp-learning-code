#include <iostream>

class Person {
  public:
    // 1. 所有对象共享同一份数据
    // 2. 编译阶段分配内存
    // 3. 类内声明，类外初始化
    static int mA; // 不初始化的话会导致报错：Person::mA undefined
};

// 必须在全局变量区声明静态成员变量，否则会报错
int Person::mA = 100;

void test1() {
    std::cout << "test1()\n";

    Person p1;
    std::cout << "p1.mA = " << p1.mA << std::endl;

    Person p2;
    p2.mA = 200;
    std::cout << "p1.mA = " << p1.mA << std::endl;

    std::cout << "\n";
}

void test2() {
    std::cout << "test2()\n";

    Person p;

    // 两种访问方式
    // 1. 通过对象进行访问
    // 2. 通过类名进行访问
    std::cout << p.mA << std::endl << Person::mA;

    std::cout << "\n";
}

int main() {
    test1();
    test2();
}