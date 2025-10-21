#include <iostream>
using namespace std;

// 定义函数模板
template <typename T> void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    Swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    double c = 2.3, d = 3.14;
    cout << "Before swap: c = " << c << ", d = " << d << endl;
    Swap(c, d);
    cout << "After swap: c = " << c << ", d = " << d << endl;
}