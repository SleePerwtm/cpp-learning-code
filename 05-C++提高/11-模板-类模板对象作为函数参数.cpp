#include <iostream>
#include <string>
using namespace std;

template <class NameType, class AgeType> class Person {
  public:
    NameType name_;
    AgeType age_;
    Person(NameType name, AgeType age) : name_(name), age_(age) {}
    void PrintInfo() {
        cout << "Name: " << name_ << endl;
        cout << "Age: " << age_ << endl;
    }
};

// 指定传入类型为Person<string, int>
void PrintPerson1(Person<string, int>& p) { p.PrintInfo(); }

// 类参数模板化
template <typename T1, typename T2> void PrintPerson2(Person<T1, T2>& p) {
    p.PrintInfo();
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
}

// 类模板化
template <class T> void PrintPerson3(T& p) {
    p.PrintInfo();
    cout << typeid(T).name() << endl;
}

int main() {
    Person<string, int> p1("张三", 20);
    PrintPerson1(p1);
    PrintPerson2(p1);
    PrintPerson3(p1);
}