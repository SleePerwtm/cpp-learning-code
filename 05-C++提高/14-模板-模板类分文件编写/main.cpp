// #include "person.h" //
// 会编译错误，显示PrintInfo()函数未定义，原因是编译器找不到PrintInfo()函数的定义，因为定义在person.cpp中，而main.cpp中没有包含person.cpp

// 解决方法：
// #include "person.cpp" // 1
#include "person.hpp" // 2，主流的解决方法，将声明和定义放在同一个文件中
using namespace std;

int main() {
    Person<string, int> p1("张三", 20);
    p1.PrintInfo();
}