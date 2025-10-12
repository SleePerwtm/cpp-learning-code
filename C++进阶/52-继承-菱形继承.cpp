#include <iostream>

class Animal {
  public:
    int mAge;
};

class Sheep : public Animal {};

class Camel : public Animal {};

class SheepCamel : public Sheep, public Camel {};

// SheepCamel类中存在两个mAge成员变量，分别属于Sheep和Camel类，这就产生了菱形继承问题
void test1() {
    SheepCamel sc;
    sc.Sheep::mAge = 10;
    sc.Camel::mAge = 20;

    std::cout << "Sheep age: " << sc.Sheep::mAge << std::endl;
    std::cout << "Tuo age: " << sc.Camel::mAge << std::endl;
}
// 这个类的对象模型长这样：
// 52-继承-菱形继承.cpp
//
// class SheepCamel        size(8):
//         +---
//  0      | +--- (base class Sheep)
//  0      | | +--- (base class Animal)
//  0      | | | mAge
//         | | +---
//         | +---
//  4      | +--- (base class Camel)
//  4      | | +--- (base class Animal)
//  4      | | | mAge
//         | | +---
//         | +---
//         +---

// 解决菱形继承问题的方法是：使用虚继承
class Sheep2 : virtual public Animal {};

class Camel2 : virtual public Animal {};

class SheepCamel2 : public Sheep2, public Camel2 {};

void test2() {
    SheepCamel2 sc;
    sc.Sheep2::mAge = 10;
    sc.Camel2::mAge = 20;
    sc.mAge = 30;

    // 此时以下三个变量地址相同
    std::cout << "Sheep age: " << sc.Sheep2::mAge << std::endl;
    std::cout << "Tuo age: " << sc.Camel2::mAge << std::endl;
    std::cout << "mAge: " << sc.mAge << std::endl;

    std::cout<<sizeof(SheepCamel);
}

// 这个类的对象模型长这样：
// 52-继承-菱形继承.cpp
//
// class SheepCamel2       size(12):
//         +---
//  0      | +--- (base class Sheep2)
//  0      | | {vbptr}
//         | +---
//  4      | +--- (base class Camel2)
//  4      | | {vbptr}
//         | +---
//         +---
//         +--- (virtual base Animal)
//  8      | mAge
//         +---

// SheepCamel2::$vbtable@Sheep2@:
//  0      | 0
//  1      | 8 (SheepCamel2d(Sheep2+0)Animal)

// SheepCamel2::$vbtable@Camel2@:
//  0      | 0
//  1      | 4 (SheepCamel2d(Camel2+0)Animal)
// vbi:       class  offset o.vbptr  o.vbte fVtorDisp
//           Animal       8       0       4 0

int main() {
    test1();
    test2();
}