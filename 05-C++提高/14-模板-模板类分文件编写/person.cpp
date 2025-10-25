#include "person.h"
using namespace std;

template <class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age)
    : name_(name), age_(age) {}

template <class NameType, class AgeType>
void Person<NameType, AgeType>::PrintInfo() {
    cout << "Name: " << name_ << endl;
    cout << "Age: " << age_ << endl;
}