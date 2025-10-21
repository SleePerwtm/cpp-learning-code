#include <iostream>
using namespace std;

int *func()
{
    int *p = new int(10);
    return p;
}

int main()
{
    int *p = func();
    cout << *p << endl;
    delete p;           // 释放内存
    cout << *p << endl; // 释放内存后再访问，先前定义的变量p已经失效，或许会导致报错
}