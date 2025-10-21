#include <iostream>
using namespace std;

int main()
{
    int array[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    cout << "数组占用的空间大小为 "
         << sizeof(array) << endl; // 输出数组占用的字节数总长
    cout << "数组中单个元素占用的空间大小为 "
         << sizeof(array[0]) << endl; // 输出数组单个元素占用字节数
    cout << "数组中元素的个数为 "
         << sizeof(array) / sizeof(array[0]) << endl; // 输出数组中包含的元素个数

    cout << "数组的首地址为 " << array << endl;
    return 0;
}