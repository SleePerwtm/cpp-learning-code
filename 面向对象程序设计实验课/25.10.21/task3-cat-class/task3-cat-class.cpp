#include <iostream>
using namespace std;

class Cat {
  public:
    static int getNumOfCats() { return numOfCats; }
    static void setNumOfCats(int n) { numOfCats = n; }

  private:
    static int numOfCats;
};

int Cat::numOfCats = 0;

int main() {
    cout << "Number of cats: " << Cat::getNumOfCats() << endl;
    Cat::setNumOfCats(10);
    cout << "Number of cats: " << Cat::getNumOfCats() << endl;

    Cat cat1;
    cat1.setNumOfCats(5);
    cout << "Number of cats: " << cat1.getNumOfCats() << endl;

    Cat cat2;
    cat2.setNumOfCats(15);
    cout << "Number of cats: " << cat1.getNumOfCats() << endl;
}