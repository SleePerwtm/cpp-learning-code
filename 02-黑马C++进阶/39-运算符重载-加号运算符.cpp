#include <iostream>

class Vector3 {
  public:
    double x, y, z;
    Vector3(double x = 0, double y = 0, double z = 0);

    // 成员函数重载加号运算符
    Vector3 operator+(const Vector3& v);
};

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

// 成员函数重载加号运算符
Vector3 Vector3::operator+(const Vector3& v) {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

// 全局函数重载加号运算符
Vector3 operator+(const Vector3& v1, const Vector3& v2) {
    return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

void test1() {
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);

    Vector3 v3 = v1 + v2;
    // Vector3 v3 = v1.operator+(v2); // 等价写法

    std::cout << "v3.x = " << v3.x << std::endl;
    std::cout << "v3.y = " << v3.y << std::endl;
    std::cout << "v3.z = " << v3.z << std::endl;
}

int main() { test1(); }