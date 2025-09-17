#include <iostream>
using namespace std;

int &func()
{
    static int a = 10;
    return a;
}

int *func2()
{
    static int a = 10;
    return &a;
}

int main()
{
    int &ref = func();
    cout << "ref = " << ref << endl;
    func() = 20; // 返回的引用类型可以作为左值
    cout << "ref = " << ref << endl;

    int *p = func2();
    cout << "*p = " << *p << endl;
    *func2() = 20; // 对返回的指针类型进行解引用后可以作为左值
    cout << "*p = " << *p << endl;
    return 0;
}