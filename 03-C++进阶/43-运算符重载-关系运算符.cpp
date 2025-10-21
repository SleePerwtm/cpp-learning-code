#include <iostream>

class Vector3 {
  public:
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    bool operator!=(const Vector3& other) const { return !(*this == other); }
    double x, y, z;
};

void test1() {
    Vector3 v1(1, 2, 2);
    Vector3 v2(1, 2, 3);
    if (v1 == v2) {
        std::cout << "v1 == v2" << std::endl;
    } else {
        std::cout << "v1 != v2" << std::endl;
    }
}

void test2() {
    Vector3 v1(1, 2, 2);
    Vector3 v2(1, 2, 3);
    if (v1 != v2) {
        std::cout << "v1 != v2" << std::endl;
    } else {
        std::cout << "v1 == v2" << std::endl;
    }
}

int main() {
    test1();
    test2();
}