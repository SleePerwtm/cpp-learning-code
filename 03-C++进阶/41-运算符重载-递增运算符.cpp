#include <iostream>

class MyInt {
  public:
    MyInt(int val = 0) : val(val) {};
    MyInt& operator++();   // 前置递增运算符重载
    MyInt operator++(int); // 后置递增运算符重载
    int val;
};

MyInt& MyInt::operator++() {
    val++;
    return *this;
}

// int作为占位参数，用于区分前置和后置递增
MyInt MyInt::operator++(int) {
    MyInt temp = *this;
    val++;
    return temp;
}

void test1() {
    MyInt myint(10);
    std::cout << "myint = " << myint.val << std::endl;
    ++myint;
    std::cout << "myint = " << myint.val << std::endl;

    MyInt myint2 = myint++;
    std::cout << "myint = " << myint.val << std::endl;
    std::cout << "myint2 = " << myint2.val << std::endl;
}

int main() { test1(); }