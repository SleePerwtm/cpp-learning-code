#include <iostream>
using namespace std;

// 全局变量
int g_a = 10, g_b = 20;

// 静态全局变量
static int sg_a = 10, sg_b = 20;

// const 修饰的全局变量
const int cg_a = 10, cg_b = 20;

int main()
{
    // 局部变量
    int a = 10, b = 20;

    cout << "局部变量a的地址\t\t" << &a << endl;
    cout << "局部变量b的地址\t\t" << &b << endl;

    cout << "全局变量g_a的地址\t" << &g_a << endl;
    cout << "全局变量g_b的地址\t" << &g_b << endl;

    // 静态局部变量
    static int s_a = 10, s_b = 20;

    cout << "静态局部变量s_a的地址\t" << &s_a << endl;
    cout << "静态局部变量s_b的地址\t" << &s_b << endl;

    cout << "静态全局变量sg_a的地址\t" << &sg_a << endl;
    cout << "静态全局变量sg_b的地址\t" << &sg_b << endl;

    /*常量*/
    // 字符串常量
    cout << "字符串常量的地址\t" << &"hello world" << endl;

    // const 修饰的局部变量
    const int c_a = 10, c_b = 20;

    cout << "局部常量c_a的地址\t" << &c_a << endl;
    cout << "局部常量c_b的地址\t" << &c_b << endl;

    cout << "全局常量cg_a的地址\t" << &cg_a << endl;
    cout << "全局常量cg_b的地址\t" << &cg_b << endl;
}