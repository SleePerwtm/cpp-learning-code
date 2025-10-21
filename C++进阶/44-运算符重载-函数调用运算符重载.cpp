#include <iostream>
#include <string>
using std::string;

class MyPrint {
  public:
    void operator()(string text) { std::cout << text << std::endl; }
};

void test1() {
    MyPrint myprint;
    myprint("A");
}

class MyAdd {
  public:
    int operator()(int a, int b) { return a + b; }
    double operator()(double a, double b) { return a + b; }
    double operator()(double a, int b) { return a + b; }
    double operator()(int a, double b) { return a + b; }
};

void test2() {
    MyAdd myadd;
    double result = myadd(2, 3.3);
    std::cout << result << std::endl;
    new MyAdd;
}

void test3() {
    // 匿名对象调用
    std::cout << MyAdd()(2.2, 3) << std::endl;
}

int main() {
    test1();
    test2();
    test3();
}