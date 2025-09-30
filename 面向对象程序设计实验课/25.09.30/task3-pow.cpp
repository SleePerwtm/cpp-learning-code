#include <iostream>
#include <math.h> // 使用math.h中的pow()函数
using namespace std;

int main() {
    cout << "输入底数与指数(空格隔开)：";
    double x, y, p;
    cin >> x >> y;
    p = pow(x, y);
    cout << "结果为：" << p << endl;

    return 0;
}