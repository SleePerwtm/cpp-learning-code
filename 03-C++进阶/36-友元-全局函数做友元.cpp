#include <iostream>
using std::string;

class Building {
    // 将全局函数goodFriend声明为Building类的友元
    friend void goodFriend(Building* building);

  public:
    Building() {
        mSittingRoom = "Sitting Room";
        mBedroom = "Bedroom";
    }
    string mSittingRoom;

  private:
    string mBedroom;
};

void goodFriend(Building* building) {
    std::cout << "好朋友正在访问：" << building->mSittingRoom << std::endl;
    std::cout << "好朋友正在访问：" << building->mBedroom
              << std::endl; // 默认无法访问私有成员，需要在类内声明为友元
}

void test1() {
    Building building;
    goodFriend(&building);
}

int main() { test1(); }