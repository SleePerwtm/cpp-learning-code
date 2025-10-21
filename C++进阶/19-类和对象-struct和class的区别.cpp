#include <iostream>
using namespace std;

// struct和class的区别
// struct 的默认访问权限是 public
// class  的默认访问权限是 private

class C1
{
    int m_A; // private
};

struct C2
{
    int m_A; // public
};

int main()
{
    C1 c1;
    C2 c2;

    // cout << "c1.m_A = " << c1.m_A << endl; // 报错，private成员不能访问sss
    cout << "c2.m_A = " << c2.m_A << endl; // ok

    return 0;
}