#include <iostream>
using namespace std;

#include "client.h"

string Client::ServerName;
int Client::ClientNum = 0;

void Client::ChangeServerName(const string& new_name) {
    cout << "修改成功，新的服务器名称为：" << new_name << endl;
    ServerName = new_name; // 修改服务器名称
}