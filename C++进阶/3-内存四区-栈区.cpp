#include <iostream>
using namespace std;

int *func()
{
    int a = 10;
    return &a;
}

int main()
{
    int *p = func();
    cout << p << endl;
    cout << *p << endl; // 会报错，局部变量的地址在函数调用结束后就被释放掉了
}