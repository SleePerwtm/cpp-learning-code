#include <iostream>
using namespace std;

template <class NameType, class AgeType> class Person {
  public:
    Person(NameType name, AgeType age) : name_(name), age_(age) {}
    NameType name_;
    AgeType age_;
    void PrintInfo() {
        cout << "Name: " << name_ << endl;
        cout << "Age: " << age_ << endl;
    }
};

int main() {
    Person<string, int> p1("张三", 20);
    p1.PrintInfo();
}