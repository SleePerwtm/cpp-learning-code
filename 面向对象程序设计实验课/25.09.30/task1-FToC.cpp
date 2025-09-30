#include <iostream>
using namespace std;

// 华氏度转摄氏度的函数
double fToC(double F) { return (F - 32) * 5 / 9; }

int main() {
    double F, C;
    cout << "输入华氏温度：";
    cin >> F;
    C = fToC(F);
    cout << "对应的摄氏温度为：" << C << "°C" << endl;

    return 0;
}