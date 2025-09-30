#include <iostream>
using namespace std;

// 返回两个整型数中的最大值
int maxNumber(int a, int b) { return a > b ? a : b; }

// 返回三个整型数中的最大值
int maxNumber(int a, int b, int c) {
    int max;
    max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}

// 返回两个双精度浮点型数中的最大值
double maxNumber(double a, double b) { return a > b ? a : b; }

// 返回三个双精度浮点型数中的最大值
double maxNumber(double a, double b, double c) {
    double max;
    max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}

int main() {
    int num, type;
    cout << "输入数字个数(2或3)：";
    cin >> num;
    cout << "输入数字类型(1表示int，2表示double)：";
    cin >> type;
    cout << "输入数字(空格隔开)：";
    int iMax, iA, iB, iC;
    double dMax, dA, dB, dC;
    if (type == 1) {
        if (num == 2) {
            cin >> iA >> iB;
            iMax = maxNumber(iA, iB);
        } else if (num == 3) {
            cin >> iA >> iB >> iC;
            iMax = maxNumber(iA, iB, iC);
        }
        cout << "最大值为：" << iMax << endl;
    } else if (type == 2) {
        if (num == 2) {
            cin >> dA >> dB;
            dMax = maxNumber(dA, dB);
        } else if (num == 3) {
            cin >> dA >> dB >> dC;
            dMax = maxNumber(dA, dB, dC);
        }
        cout << "最大值为：" << dMax << endl;
    }

    return 0;
}
