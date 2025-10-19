#include <iostream>

class Person {
  public:
    void showClassName() {
        std::cout << "This is a Person class." << std::endl;
    }

    void showAge() {
        // 使用空指针访问调用成员变量的成员函数会报错内存访问异常
        // 因此需要判断指针是否为空，如果为空则不执行，提升程序的健壮性
        if (this == nullptr) {
            std::cout << "This person is a null pointer." << std::endl;
            return;
        }
        std::cout << "Age of this person is " << this->mAge << std::endl;
    }

    int mAge;
};

void test1() {
    std::cout << "test1() is called:\n";

    Person* p1 = nullptr;
    p1->showClassName();

    std::cout << "\n";
}

void test2() {
    std::cout << "test2() is called:\n";

    Person* p1 = nullptr;
    p1->showAge();

    std::cout << "\n";
}

int main() {
    test1();
    test2();
}