#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager : public Worker {
  public:
    // 构造函数
    Manager(int id, string name, int deptId);

    // 显示个人信息
    virtual void DisplayInfo() override;

    // 获取岗位名称
    virtual string GetDepartmentName() override;
};