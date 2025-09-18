#include <iostream>
using namespace std;

void add(int a, int b, int) // 第三个int是占位参数，必须传值但是不会被使用
{
    cout << a + b << endl;
}

int main()
{
    int a = 10, b = 20, c = 30;
    add(a, b, c);
    return 0;
}