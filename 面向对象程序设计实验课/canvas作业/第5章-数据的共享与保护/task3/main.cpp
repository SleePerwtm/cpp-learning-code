#include <iostream>
using namespace std;

#include "classes.cpp"

int main() {
    X x;
    x.set_i(0);
    cout << "x.i_ = " << x.get_i() << endl;

    Y y;
    y.g(&x);
    cout << "after y.g(&x), x.i_ = " << x.get_i() << endl;

    Z z;
    z.f(&x);
    cout << "after z.f(&x), x.i_ = " << x.get_i() << endl;

    h(&x);
    cout << "after h(&x), x.i_ = " << x.get_i() << endl;
}