#include <fstream>
using namespace std;

class Person {
  public:
    char name[64];
    int age;
};

int main() {
    Person p = {"张三", 18};
    ofstream ofs;
    ofs.open("63-person.txt", ios::binary | ios::out);
    ofs.write((char*)&p, sizeof(p));
    ofs.close();
}