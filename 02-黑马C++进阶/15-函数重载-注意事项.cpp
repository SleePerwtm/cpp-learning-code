#include <iostream>
using namespace std;

/*引用作为重载函数的形参*/
void func(int &a)
{
    cout << "调用func(int& a)" << endl;
}
void func(const int &a)
{
    cout << "调用func(const int& a)" << endl;
}

/*函数重载遇到默认参数*/
void func2(int a)
{
    cout << "调用func2(int a)" << endl;
}
void func2(int a, int b = 0)
{
    cout << "调用func2(int a, int b)" << endl;
}

int main()
{
    int a = 10;
    func(a);
    func(10);

    // func(10); // 调用的时候需要保证只满足一个重载的调用条件（无二义性）
}