#pragma once // 防止重复包含头文件
#include <iostream>
using namespace std;

// 点类
class Point
{
public:
    // 设置x坐标
    void setX(double x);
    // 获取x坐标
    double getX();
    // 设置y坐标
    void setY(double y);
    // 获取y坐标
    double getY();

private:
    double m_X; // x坐标
    double m_Y; // y坐标
};