#include <iostream>
using namespace std;

int* fn1() {
    static int n = 0;
    n++;
    return &n;
}

int main() {
    int* result = nullptr;
    for (int i = 0; i < 10; i++) {
        result = fn1();
    }
    cout << *result << endl;
}