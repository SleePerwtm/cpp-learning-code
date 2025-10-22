#include <iostream>
using namespace std;

template <typename T> void SelectionSort(T arr[], int arr_len) {
    for (int i = 0; i < arr_len - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < arr_len; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

template <typename T> void PrintArray(T arr[], int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void TestCharArraySort() {
    char arr[10] = {'b', 'c', 'a', 'e', 'd', 'f', 'g', 'h', 'i', 'j'};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sort: ";
    PrintArray(arr, len);

    SelectionSort(arr, len);

    cout << "After Sort: ";
    PrintArray(arr, len);
}

void TestIntArraySort() {
    int arr[5] = {5, 2, 8, 3, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sort: ";
    PrintArray(arr, len);

    SelectionSort(arr, len);

    cout << "After Sort: ";
    PrintArray(arr, len);
}

int main() {
    TestCharArraySort();
    TestIntArraySort();
}