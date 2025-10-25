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