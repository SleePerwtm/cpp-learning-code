#include <iostream>

class Person {
  public:
    Person(int age) {
        this->age = age;
    } // 1. 可以解决命名冲突，区分开函数形参与类成员变量

    Person& personAddAge(Person& p) {
        this->age += p.age;
        return *this; // 2. 可以返回对象本身，实现链式调用
    }

    int age;
};

void test1() {
    std::cout << "test1() is called:\n";

    Person p1(20);

    std::cout << "age of p1: " << p1.age << std::endl;

    std::cout << "\n";
}

void test2() {
    std::cout << "test2() is called:\n";

    Person p1(20);
    Person p2(20);

    p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);
    std::cout << "age of p2: " << p2.age << std::endl;

    std::cout << "\n";
}

int main() {
    test1();
    test2();
}