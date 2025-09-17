#include <iostream>
using namespace std;

void testArr(int len)
{
    int *p = new int[len];
    for (int i = 0; i < len; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < len; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    delete[] p;
}

int main()
{
    int len;
    cout << "请输入动态数组长度：";
    cin >> len;
    testArr(len);
    return 0;
}