#include <iostream>
using namespace std;

/*水仙花数是指一个n位数（n≥3），它的每个位上的数字的n次幂之和等于它本身。*/
int main()
{
    int a, b, c;
    for (int i = 100; i < 1000; i++)
    {
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100;

        if (a * a * a + b * b * b + c * c * c == i)
            cout << i << '\n';
    }
    return 0;
}