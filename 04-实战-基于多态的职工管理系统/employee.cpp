#include <iostream>
#include <string>
using namespace std;
#include "employee.h"

Employee::Employee(int id, string name, int department_id) {
    id_ = id;
    name_ = name;
    department_id_ = department_id;
}

void Employee::DisplayInfo() {
    cout << "职工编号：" << id_ << "\t职工姓名：" << name_ << "\t岗位："
         << GetDepartmentName() << "\t岗位职责：完成经理交给的任务"<< endl;
}

string Employee::GetDepartmentName() { return string("员工"); }