#include <iostream>
using std::string;

class Building;

class GoodFriend {
  public:
    GoodFriend();
    void visit();
    Building* building;
};

class Building {
    // 将类goodFriend声明为Building类的友元
    friend class GoodFriend;

  public:
    Building();
    string mSittingRoom;

  private:
    string mBedroom;
};

// 类外定义
Building::Building() {
    mSittingRoom = "Sitting Room";
    mBedroom = "Bedroom";
}

GoodFriend::GoodFriend() { building = new Building; }
void GoodFriend::visit() {
    std::cout << "好朋友类正在访问：" << building->mSittingRoom << std::endl;
    std::cout << "好朋友类正在访问：" << building->mBedroom << std::endl;
}

void test1() {
    GoodFriend goodFriend;
    goodFriend.visit();
}

int main() { test1(); }