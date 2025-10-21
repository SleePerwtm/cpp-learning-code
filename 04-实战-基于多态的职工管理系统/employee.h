#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee : public Worker {
  public:
    // 构造函数
    Employee(int id, string name, int department_id);

    // 显示个人信息
    virtual void DisplayInfo() override;

    // 获取岗位名称
    virtual string GetDepartmentName() override;
};