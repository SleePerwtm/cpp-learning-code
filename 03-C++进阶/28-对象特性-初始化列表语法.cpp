#include <iostream>
using namespace std;

class Person {
  public:
    // 传统初始化
    // Person(int a, int b, int c)
    // {
    //     mA = a;
    //     mB = b;
    //     mC = c;
    // }

    Person(int a, int b, int c) : mA(a), mB(b), mC(c) {}

    void printPerson() {
        cout << "mA = " << mA << endl;
        cout << "mB = " << mB << endl;
        cout << "mC = " << mC << endl;
    }

  private:
    int mA;
    int mB;
    int mC;
};

void test() {
    Person p(10, 20, 30);
    p.printPerson();
}

int main() {
    test();
    return 0;
}