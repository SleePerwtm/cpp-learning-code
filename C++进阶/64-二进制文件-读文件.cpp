#include <fstream>
#include <iostream>
using namespace std;

class Person {
  public:
    char name[64];
    int age;
};

int main() {
    Person p;
    ifstream ifs;
    ifs.open("63-person.txt", ios::binary | ios::in);
    ifs.read((char*)&p, sizeof(Person));
    ifs.close();
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
}