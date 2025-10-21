#include <iostream>
using namespace std;

void func(const int &a) // 使用常量引用，可以避免在函数内部意外修改变量a的值
{
    // a = 20; // 会报错
    cout << "a = " << a << endl;
}

int main()
{
    int a = 10;
    func(a);
}