#include <iostream>
using namespace std;

void swap(int num1, int num2);
void swap2(int *num1, int *num2);

int main()
{
    int a = 10, b = 20;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl
         << endl;

    swap(a, b);

    cout << "调用swap函数后：\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl
         << endl;
}

void swap(int num1, int num2)
{
    cout << "调用swap函数：\n交换前：\n";
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：\n";
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << endl;
}
