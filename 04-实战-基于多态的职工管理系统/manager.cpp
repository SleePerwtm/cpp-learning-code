#include <iostream>
#include <string>
using namespace std;
#include "manager.h"

Manager::Manager(int id, string name, int department_id) {
    id_ = id;
    name_ = name;
    department_id_ = department_id;
}

void Manager::DisplayInfo() {
    cout << "职工编号：" << id_ << "\t职工姓名：" << name_ << "\t岗位："
         << GetDepartmentName()
         << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::GetDepartmentName() { return string("经理"); }