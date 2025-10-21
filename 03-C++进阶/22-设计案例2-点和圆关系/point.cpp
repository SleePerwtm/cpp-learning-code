#include "point.h"

/*需要指明函数属于Point类作用域*/

// 设置x坐标
void Point::setX(double x) { m_X = x; }
// 获取x坐标
double Point::getX() { return m_X; }
// 设置y坐标
void Point::setY(double y) { m_Y = y; }
// 获取y坐标
double Point::getY() { return m_Y; }
