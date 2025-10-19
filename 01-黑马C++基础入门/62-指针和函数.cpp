#include <iostream>
using namespace std;

// 传入地址
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "a = " << a << endl
         << "b = " << b << endl;

    swap(&a, &b);

    cout << "a = " << a << endl
         << "b = " << b << endl;
}