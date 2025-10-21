#include <iostream>
using namespace std;

#include "client.h"

int main() {
    Client c1;
    c1.ServerName = "Server1";
    cout << "c1.ServerName = " << c1.ServerName << endl;
    c1.ClientNum++;
    cout << "c1.ClientNum = " << c1.ClientNum << endl;

    Client c2;
    c2.ChangeServerName("Server2");
    cout << "c2.ServerName = " << c2.ServerName << endl;
    c2.ClientNum++;
    cout << "c2.ClientNum = " << c2.ClientNum << endl;
}