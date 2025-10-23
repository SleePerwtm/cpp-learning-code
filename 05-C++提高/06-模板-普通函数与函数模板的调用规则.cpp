#include <iostream>
using namespace std;

// 调用规则如下：
// 1. 如果函数模板和普通函数都可以实现，优先调用普通函数
// 2. 可以通过空模板参数列表来强制调用函数模板
// 3. 函数模板也可以发生重载
// 4. 如果函数模板可以产生更好的匹配,优先调用函数模板

int Add(int a, int b) {
    cout << "调用普通函数" << endl;
    return a + b;
}

template <typename T> T Add(T a, T b) {
    cout << "调用两个参数的模板函数" << endl;
    return a + b;
}

template <typename T> T Add(T a, T b, T c) {
    cout << "调用重载的三参数模板函数" << endl;
    return a + b + c;
}

void Test1() {
    int a = 10, b = 20;
    cout << "Add(a, b) = " << Add(a, b) << endl; // 优先调用普通函数
}

void Test2() {
    int a = 10, b = 20;
    cout << "Add<int>(a, b) = " << Add<>(a, b) << endl; // 强制调用函数模板
}

void Test3() {
    int a = 10, b = 20, c = 30;
    cout << "Add(a, b, c) = " << Add(a, b, c) << endl; // 调用重载的函数模板
}

void Test4() {
    short a = 10, b = 20;
    cout
        << "Add(a, b) = " << Add(a, b)
        << endl; // 虽然隐式转换后可以匹配普通函数，但是与函数模板匹配更好，所以优先调用函数模板
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
}