#include <iostream>
using namespace std;

class Class1 {
  public:
    void Class1Func() { cout << "Class1Func" << endl; }
};

class Class2 {
  public:
    void Class2Func() { cout << "Class2Func" << endl; }
};

template <class T> class TestClass {
  public:
    T obj; // 此时还无法确定obj的类型，因此下面的两个成员函数不会报错
    void Func1() { obj.Class1Func(); }
    void Func2() { obj.Class2Func(); }
};

int main() {
    TestClass<Class1> obj1; // 确定TestClass的模板参数为Class1
    obj1.Func1();
    // obj1.Func2(); // 编译器报错，因为obj1为Class1类型，没有Class2Func成员函数

    TestClass<Class2> obj2; // 确定TestClass的模板参数为Class2
    // obj2.Func1(); // 编译器报错，因为obj2为Class2类型，没有Class1Func成员函数
    obj2.Func2();
}