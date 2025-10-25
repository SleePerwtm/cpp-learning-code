#include <iostream>
using namespace std;

template <class T> class Base {
  public:
    T value_;
};

// class Derived : public Base {}; // 错误：继承模板类时，必须指定模板参数

// 指定模板参数
class Derived : public Base<int> {};

// 模板类继承模板类
template <class T, class T2> class TemplateDerived : public Base<T> {
  public:
    T2 value2_;
};

int main() {}