#pragma once // 防止重复包含头文件
#include <iostream>
#include "point.h"
using namespace std;

// 圆类
class Circle
{
public:
    // 设置半径
    void setR(double r);
    // 获取半径
    double getR();
    // 设置圆心坐标
    void setCenter(Point center);
    // 获取圆心坐标
    Point getCenter();

private:
    double m_R;     // 半径
    Point m_Center; // 圆心坐标
};