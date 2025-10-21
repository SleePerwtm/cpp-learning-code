#include <iostream>
using namespace std;

int main()
{
    // C 风格字符串
    char cstr[] = "c\thello world!";
    printf("%s\n", cstr);

    // C++ 风格字符串
    string cppstr = "cpp\thello world!";
    cout << cppstr << endl;

    return 0;
}