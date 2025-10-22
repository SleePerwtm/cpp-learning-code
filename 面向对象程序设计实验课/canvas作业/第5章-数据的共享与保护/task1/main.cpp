#include <iostream>
using namespace std;

#include "fn.h"

string str;

int main() {
    str = "main function"; // 设置全局变量
    fn();
    cout << str << endl; // 输出全局变量，查看是否被fn()修改
}