#pragma once
#include <iostream>
using namespace std;

template <class NameType, class AgeType> class Person {
  public:
    Person(NameType name, AgeType age);
    NameType name_;
    AgeType age_;
    void PrintInfo();
};

template <class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age)
    : name_(name), age_(age) {}

template <class NameType, class AgeType>
void Person<NameType, AgeType>::PrintInfo() {
    cout << "Name: " << name_ << endl;
    cout << "Age: " << age_ << endl;
}