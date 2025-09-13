#include <iostream>
using namespace std;

void bubbleSort(int *a, int size);

int main()
{
    int a[10002];
    int size = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, size);
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