#include <iostream>
using namespace std;

/*创建B对象的时候，A先构造，然后B构造，最后B析构，A析构*/

class Phone {
  public:
    Phone(string number) : mNumber(number) {
        cout << "A的构造函数被调用" << endl;
    }
    ~Phone() { cout << "A的析构函数被调用" << endl; }

    string mNumber;
};

class Person {
  public:
    Person(string name, string number) : mName(name), phone(number) {
        cout << "B的构造函数被调用" << endl;
    }
    ~Person() { cout << "B的析构函数被调用" << endl; }

    void printPerson() {
        cout << "name = " << mName << endl;
        cout << "number = " << phone.mNumber << endl;
    }

    string mName;
    Phone phone;
};

int main() {
    Person p("Tom", "1234567890");
    p.printPerson();
    return 0;
}