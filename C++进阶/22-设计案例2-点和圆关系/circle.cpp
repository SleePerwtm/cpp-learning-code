#include "point.h"
#include "circle.h"

/*需要指明函数属于Circle类作用域*/

// 设置半径
void Circle::setR(double r) { m_R = r; }
// 获取半径
double Circle::getR() { return m_R; }
// 设置圆心坐标
void Circle::setCenter(Point center) { m_Center = center; }
// 获取圆心坐标
Point Circle::getCenter() { return m_Center; }
