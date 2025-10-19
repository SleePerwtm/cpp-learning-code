#include <iostream>

class Person {};

void voidClassSize() {
    std::cout << "voidClassSize() is called:\n";

    // 空对象的大小为1个字节，用以区分不同的对象
    Person obj;
    std::cout << "Size of VoidClass's object: " << sizeof(obj) << std::endl;
    std::cout << "Size of VoidClass: " << sizeof(Person)
              << std::endl; // sizeof(类名) 返回的是类实例所占的内存字节数

    std::cout << "\n";
}

/*只有非静态成员变量会与对象存储在一起，非静态成员函数、静态成员变量、静态成员函数*/

class Test1 {
  public:
    int m1;
    int m2;
};

void test1() {
    std::cout << "test1() is called:\n";

    Test1 obj;
    std::cout << "Size of Test1's object: " << sizeof(obj) << std::endl;

    std::cout << "\n";
}

class Test2 {
  public:
    int m1;
    static int s1;
    void func() { int a; }
    static void staticFunc() { int a; }
};

int Test2::s1 = 0;

void test2() {
    std::cout << "test2() is called:\n";

    Test2 obj;
    std::cout << "Size of Test2's object: " << sizeof(obj) << std::endl;

    std::cout << "\n";
}

int main() {
    voidClassSize();
    test1();
    test2();
}