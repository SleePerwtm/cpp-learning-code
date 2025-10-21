#include <iostream>

class Vector3 {
  public:
    double x, y, z;
    Vector3(double x = 0, double y = 0, double z = 0);
};

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

// 全局函数重载左移运算符
std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "Vector3(" << v.x << ", " << v.y << ", " << v.z << ")\n";
    return os;
}

void test1() {
    Vector3 v1(1, 2, 3);
    std::cout << v1;
}

int main() { test1(); }