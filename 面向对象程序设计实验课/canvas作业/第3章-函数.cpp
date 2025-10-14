#include <cmath>
#include <iostream>

using std::string;

// 任务一：计算阶乘的函数

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return factorial(n - 1) * n;
}

void task1() {
    std::cout << "任务一：\n";
    int result;
    result = factorial(5);
    std::cout << 5 << "的阶乘为：" << result << std::endl;
}

// ========================================================

// 任务二：实现求最大值的内联函数

inline double max(double a, double b) { return a > b ? a : b; }

void task2() {
    std::cout << "任务二：\n";
    double result;
    result = max(3.14, 1.414);
    std::cout << "最大值为：" << result << std::endl;
}

// ========================================================

// 任务三：缺省形参的函数，输出学生信息

void printStudentInfo(string name, int age = 18, string sex = "男") {
    std::cout << "任务三：\n";
    std::cout << "姓名：" << name << std::endl
              << "年龄：" << age << std::endl
              << "性别：" << sex << std::endl;
}

void task3() { printStudentInfo("张三"); }

// ========================================================

// 任务四：编写重载函数实现相加功能

int add(int a, int b) { return a + b; }

double add(double a, double b) { return a + b; }

string add(string a, string b) { return a + b; }

void task4() { std::cout << "任务四：\n"; }

// ========================================================

// 任务五：使用库函数sqrt和pow计算给定数的平方根和幂

void task5() {
    std::cout << "任务五：\n";
    double x, y;
    std::cout << "输入底数：";
    std::cin >> x;
    std::cout << "输入指数：";
    std::cin >> y;
    std::cout << "平方根：" << sqrt(x) << std::endl;
    std::cout << "幂：" << pow(x, y) << std::endl;
}

int main() {
    task1();
    std::cout << "\n";
    task2();
    std::cout << "\n";
    task3();
    std::cout << "\n";
    task4();
    std::cout << "\n";
    task5();
}