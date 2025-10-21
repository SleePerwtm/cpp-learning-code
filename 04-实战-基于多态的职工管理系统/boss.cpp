#include <iostream>
#include <string>
using namespace std;
#include "boss.h"

Boss::Boss(int id, string name, int department_id) {
    id_ = id;
    name_ = name;
    department_id_ = department_id;
}

void Boss::DisplayInfo() {
    cout << "职工编号：" << id_ << "\t职工姓名：" << name_ << "\t岗位："
         << GetDepartmentName() << "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::GetDepartmentName() { return string("老板"); }