#include <iostream>

class Person {
  public:
    Person() {}
    void setAge() const {
        // mAge = 0;
        // this = nullptr; // this指针本身为指针常量 (const Person* const this)
        mCount = 0;
        std::cout << "setAge() is called.\n";
    } // 使用const修饰setAge函数，使得不允许修改成员变量
    void notConstSetAge() { mAge = 0; }
    int mAge;
    mutable int mCount; // 声明为mutable，使得成员变量可以被修改
};

void test1() {
    std::cout << "test1() is called:\n";

    Person p;
    p.setAge();

    std::cout << "\n";
}

void test2() {
    std::cout << "test2() is called:\n";

    const Person p;
    p.setAge();
    // p.notConstSetAge(); // 常对象不能调用非const成员函数

    std::cout << "\n";
}

int main() {
    test1();
    test2();
}