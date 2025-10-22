#include <iostream>
using namespace std;

// 定义函数模板
template <typename T> // 类型T推导结果必须一致
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> // 必须能推导出类型T是什么
void func() {}

int main() {
    int a = 10;
    char b = 20;
    // Swap(a, b); // 类型T推导结果不一致，编译错误

    // func(); // 无法推导出类型T，编译错误
}