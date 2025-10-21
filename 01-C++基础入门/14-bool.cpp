#include <iostream>
using namespace std;

int main()
{
    bool flag = true;
    cout << "flag = " << flag << endl;

    flag = false;
    cout << "flag = " << flag << endl;

    cout << "flag = " << !flag << endl;

    // bool类型占用字节数
    cout << "bool size = " << sizeof(bool) << endl;
}