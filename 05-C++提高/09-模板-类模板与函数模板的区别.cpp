#include <iostream>
using namespace std;

// 类模板与函数模板的区别
// 1、 类模板不能自动推导类型，函数模板可以自动推导类型。
// 2、 类模板可以有默认类型参数

template <class NameType, class AgeType = int> class Person {
  public:
    Person(NameType name, AgeType age) : name_(name), age_(age) {}
    NameType name_;
    AgeType age_;
    void PrintInfo() {
        cout << "Name: " << name_ << endl;
        cout << "Age: " << age_ << endl;
    }
};

int main() {
    Person<string> p1("张三", 20);
    p1.PrintInfo();
}