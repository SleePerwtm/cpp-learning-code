#include <iostream>
using namespace std;

int* fn1() {
    static int n = 0; // 声明并初始化静态变量
    n++;
    return &n; // 返回地址，使main函数能够访问该变量，并打印其值
}

int main() {
    int* result = fn1(); // 调用函数1次
    for (int i = 0; i < 9; i++) {
        fn1();
    } // 调用函数9次

    // cout << n << endl; // 无法访问局部变量，编译报错
    cout << *result << endl;
}