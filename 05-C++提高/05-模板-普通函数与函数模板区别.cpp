#include <iostream>
using namespace std;

// 区别：
// 1、普通函数 调用可以发生隐式类型转换
// 2、函数模板 用自动类型推导，不可以发生隐式类型转换
// 3、函数模板 用显式指定类型，可以发生隐式类型转换

int Add(int a, int b) { return a + b; }

template <typename T> T Add(T a, T b) { return a + b; }

void TestImplicitConversion() {
    int a = 10;
    char b = 2;

    int result1 = Add(a, b); // 普通函数，可以发生隐式类型转换
    int result2 =
        Add<int>(a, b); // 显式指定类型的函数模板，可以发生显隐式类型转换

    string s1 = "hello";

    // string result3 = Add(s1, "world"); //
    // 自动类型推导，不可以发生隐式类型转换
}

int main() { TestImplicitConversion(); }