#include <iostream>
using namespace std;

void add(int a, int b = 10, int c = 20, int d = 30) // 设置默认参数，默认参数都要在参数列表最后
{
    cout << a + b + c + d << endl;
}

int main()
{
    int a = 10, b = 20, c = 30, d = 40;
    add(a, b, c, d);
    return 0;
}