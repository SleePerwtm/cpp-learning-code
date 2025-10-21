#include <iostream>
using namespace std;

class Car;

class Boat {
    friend double GetTotalWeight(Boat&, Car&);

  public:
    Boat() = default;
    Boat(double weight) : weight_(weight) {}
    void set_weight(double weight) { weight_ = weight; }
    double get_weight() const { return weight_; }

  private:
    double weight_;
};

class Car {
    friend double GetTotalWeight(Boat&, Car&);

  public:
    Car() = default;
    Car(double weight) : weight_(weight) {}
    void set_weight(double weight) { weight_ = weight; }
    double get_weight() const { return weight_; }

  private:
    double weight_;
};

double GetTotalWeight(Boat& boat, Car& car) {
    return boat.weight_ + car.weight_;
}

int main() {
    Boat boat(1026.63);
    Car car(2587.02);
    double total_weight = GetTotalWeight(boat, car);
    cout << "Total weight: " << total_weight << endl;
}