#include <iostream>

class Animal {
  public:
    void speak() { std::cout << "Animal speak" << std::endl; }
    virtual void virtualSpeak() {
        std::cout << "Animal virtual speak" << std::endl;
    }
};

class Cat : public Animal {
  public:
    void speak() { std::cout << "Cat speak" << std::endl; }
    void virtualSpeak() { std::cout << "Cat virtual speak" << std::endl; }
};

class Dog : public Animal {
  public:
    void virtualSpeak() { std::cout << "Dog virtual speak" << std::endl; }
};

void doSpeak(Animal& animal) {
    // 编译阶段就已经确定了speak()函数地址，不管传Cat还是其他子类，都调用的是Animal的speak()函数
    animal.speak();
}

void doVirtualSpeak(Animal& animal) { animal.virtualSpeak(); }

void test1() {
    Cat cat;
    doSpeak(cat);
}

void test2() {
    Cat cat;
    doVirtualSpeak(cat);

    Dog dog;
    doVirtualSpeak(dog);

    Animal animal;
    doVirtualSpeak(animal);
}

int main() {
    test1();
    test2();
}