#pragma once

#include <iostream>
using namespace std;

// 声明client类
class Client {
  public:
    // 修改服务器名称
    static void ChangeServerName(const string& new_name);

    static string ServerName; // 服务器名称
    static int ClientNum;     // 已定义的客户数量
};