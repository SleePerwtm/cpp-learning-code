#include <iostream>
#include <cstring>
using namespace std;

void bubbleSort(int *a, int size);

int main()
{
    int size, a[10002];
    memset(a, 0, sizeof(a));
    cout << "输入数组长度：";
    cin >> size;
    cout << "输入数组元素，元素间用空格分割：";
    for (int i = 0; i < size; i++)
        cin >> a[i];
    bubbleSort(a, size);
    cout << endl
         << "排序后的数组为：";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}

void bubbleSort(int *a, int size)
{
    int temp;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}