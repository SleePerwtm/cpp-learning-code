#include <iostream>
using namespace std;

class Animal {
  public:
    Animal() { cout << "Animal constructor" << endl; }
    virtual void speak() { cout << "Animal speak" << endl; }
    virtual ~Animal() { cout << "Animal destructor" << endl; }
};

class Cat : public Animal {
  public:
    void speak() { cout << "Cat speak" << endl; }
    Cat(string name) {
        cout << "Cat constructor" << endl;
        this->name = new string(name);
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
        if (name != nullptr) {
            delete name;
            name = nullptr;
        }
    }

  private:
    string* name;
};

void test() {
    Animal* animal = new Cat("Tom");
    animal->speak();
    delete animal; // 必须定义虚析构函数，不然调用的会是Animal的析构函数而不是Cat的析构函数
}

int main() { test(); }