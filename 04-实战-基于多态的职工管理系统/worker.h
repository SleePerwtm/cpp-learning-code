#pragma once
#include <iostream>
using namespace std;

class Worker {
  public:
    // 显示个人信息
    virtual void DisplayInfo() = 0;

    // 获取岗位名称
    virtual string GetDepartmentName() = 0;

    int id_;            // 职工编号
    string name_;       // 职工姓名
    int department_id_; // 部门名称编号
};
