#include <iostream>
using namespace std;

class Car;

class Boat {
    friend double GetTotalWeight(Boat&, Car&); // 声明全局函数为友元

  public:
    // 构造函数
    Boat() = default;
    Boat(double weight) : weight_(weight) {}

    // 设值函数
    void set_weight(double weight) { weight_ = weight; }
    // 取值函数
    double get_weight() const { return weight_; }

  private:
    double weight_;
};

class Car {
    friend double GetTotalWeight(Boat&, Car&); // 声明全局函数为友元

  public:
    // 构造函数
    Car() = default;
    Car(double weight) : weight_(weight) {}

    // 设值函数
    void set_weight(double weight) { weight_ = weight; }
    // 取值函数
    double get_weight() const { return weight_; }

  private:
    double weight_;
};

// 计算船与车的总重量
double GetTotalWeight(Boat& boat, Car& car) {
    return boat.weight_ + car.weight_;
}

int main() {
    Boat boat(1026.63);                               // 初始化船的实例
    Car car(2587.02);                                 // 初始化车的实例
    double total_weight = GetTotalWeight(boat, car);  // 调用全局函数计算总重量
    cout << "Total weight: " << total_weight << endl; // 输出总重量
}