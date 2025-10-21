#include <iostream>
using namespace std;

#include "fn.h"

string str;

int main() {
    str = "main function";
    fn();
    cout << str << endl;
}