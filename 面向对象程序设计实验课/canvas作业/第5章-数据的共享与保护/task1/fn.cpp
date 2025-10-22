#include <iostream>
using namespace std;

#include "fn.h"

extern string str;

void fn() {
    str = "fn"; // 设置为 "fn"，标记函数fn()修改了全局变量 str
}