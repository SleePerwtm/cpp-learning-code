#include <iostream>

/*默认赋值运算符实现的都是浅拷贝*/
/*需要深拷贝的对象，要自定义赋值运算符*/

class Person {
  public:
    Person(int age) : pAge(new int(age)) {}
    ~Person() {
        if (pAge != nullptr) {
            delete pAge;
            pAge = nullptr;
        }
    }

    Person& operator=(const Person& p) {
        if (pAge != nullptr) {
            delete pAge;
            pAge = nullptr;
        }

        pAge = new int(*p.pAge); // 深拷贝
        return *this;
    }

    int* pAge;
};

void test1() {
    Person p1(25);
    Person p2(18);
    Person p3(20);

    p3 = p1 = p2;

    std::cout << "p1.pAge = " << *p1.pAge << std::endl;
    std::cout << "p2.pAge = " << *p2.pAge << std::endl;
    std::cout << "p3.pAge = " << *p3.pAge << std::endl;
}

int main() { test1(); }