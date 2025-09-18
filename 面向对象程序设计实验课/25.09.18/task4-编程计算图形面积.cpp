#include <iostream>
using namespace std;

void printMenu()
{
    cout << "==============================\n";
    cout << "选择图形类型：\n";
    cout << "1. 圆形\n";
    cout << "2. 矩形\n";
    cout << "3. 正方形\n";
    cout << "0. 退出\n";
    cout << "==============================\n";
    cout << "请输入图形类型序号：";
}

int main()
{
    printMenu();

    const double PI = 3.14159265;
    double area;

    int type;
    cin >> type;

    while (type != 0)
    {
        switch (type)
        {
        case 1:
            cout << "请输入圆的半径：";
            double r;
            cin >> r;
            area = PI * r * r;
            cout << "圆的面积为：" << area << endl;
            break;
        case 2:
            cout << "请输入矩形的长和宽：";
            double length, width;
            cin >> length >> width;
            area = length * width;
            cout << "矩形的面积为：" << area << endl;
            break;
        case 3:
            cout << "请输入正方形的边长：";
            double side;
            cin >> side;
            area = side * side;
            cout << "正方形的面积为：" << area << endl;
            break;
        }
        
        printMenu();
        cin >> type;
    }
    cout << "程序退出！\n";
    return 0;
}