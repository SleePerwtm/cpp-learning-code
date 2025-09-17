#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &ref = a; // int *ref = &a;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl; // 自动将ref转为*ref
    ref = 20;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    return 0;
}