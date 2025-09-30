#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "输入要获得第几项的值：";
    cin >> n;
    cout << "斐波那契数列第" << n << "项为：" << fibonacci(n);

    return 0;
}