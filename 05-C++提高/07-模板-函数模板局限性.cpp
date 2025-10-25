#include <iostream>
using namespace std;

class Person {
  public:
    Person(string name, int age) : name_(name), age_(age) {}
    string name_;
    int age_;
};

template <typename T> bool IsEqual(const T& a, const T& b) { return a == b; }

// 具体化模板，优先于常规函数模板
template <> bool IsEqual(const Person& a, const Person& b) {
    return a.name_ == b.name_ && a.age_ == b.age_;
}

int main() {
    Person p1("张三", 20), p2("李四", 25);
    cout << "IsEqual(1, 2) = " << IsEqual(1, 2) << endl;
    cout << "IsEqual(p1, p2) = " << IsEqual(p1, p2)
         << endl; // 默认报错，因为没有定义 Person 的 == 操作符
}