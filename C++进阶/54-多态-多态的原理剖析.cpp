#include <iostream>
using namespace std;

class Animal {
  public:
    virtual void speak() { cout << "Animal speak" << endl; }
};

class Cat : public Animal {
  public:
    void speak() { cout << "Cat speak" << endl; }
};

class Dog : public Animal {
  public:
    void speak() { cout << "Dog speak" << endl; }
};

void doSpeak(Animal& animal) { animal.speak(); }

int main() {
    Cat cat;
    doSpeak(cat);
}

// 实际上，虚函数类似于虚继承，子类、父类中会存储vfptr(virtual function
// pointer)，指向vftable(virtual function
// table)，调用时根据vfptr找到对应函数指针，然后调用。
// 多态的原理就是通过虚函数表来实现的，子类中重写了父类的虚函数，在调用时，根据对象实际类型，找到对应的函数指针，调用。子类指向的虚函数表中，存储的是子类的函数指针，而不是父类的函数指针。

// 查看父类与子类的对象模型：

// 父类Animal：
// class Animal    size(4):
//         +---
//  0      | {vfptr}
//         +---
//
// Animal::$vftable@:
//         | &Animal_meta
//         |  0
//  0      | &Animal::speak
//
// Animal::speak this adjustor: 0

// 子类Cat：
// class Cat       size(4):
//         +---
//  0      | +--- (base class Animal)
//  0      | | {vfptr}
//         | +---
//         +---
//
// Cat::$vftable@:
//         | &Cat_meta
//         |  0
//  0      | &Cat::speak
//
// Cat::speak this adjustor: 0
