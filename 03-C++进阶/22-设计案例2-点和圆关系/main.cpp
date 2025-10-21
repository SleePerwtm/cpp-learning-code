#include <iostream>
#include <cmath>
#include "point.h"
#include "circle.h"
using namespace std;

// 判断点与圆的位置关系
void isInCircle(Point &p, Circle &c)
{
    double distance = sqrt(pow(p.getX() - c.getCenter().getX(), 2) + pow(p.getY() - c.getCenter().getY(), 2));
    if (distance < c.getR())
        cout << "点" << "(" << p.getX() << "," << p.getY() << ")" << "在圆心为" << "(" << c.getCenter().getX() << "," << c.getCenter().getY() << ")" << "半径为" << c.getR() << "的圆内" << endl;
    else if (distance == c.getR())
        cout << "点" << "(" << p.getX() << "," << p.getY() << ")" << "在圆心为" << "(" << c.getCenter().getX() << "," << c.getCenter().getY() << ")" << "半径为" << c.getR() << "的圆上" << endl;
    else
        cout << "点" << "(" << p.getX() << "," << p.getY() << ")" << "在圆心为" << "(" << c.getCenter().getX() << "," << c.getCenter().getY() << ")" << "半径为" << c.getR() << "的圆外" << endl;
}

int main()
{
    Point p, center;
    Circle c;

    p.setX(0);
    p.setY(0);

    center.setX(1);
    center.setY(1);

    c.setR(1);
    c.setCenter(center);

    isInCircle(p, c);

    return 0;
}