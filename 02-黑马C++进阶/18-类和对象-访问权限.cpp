#include <iostream>
#include <string>
using std::string;

// 访问权限有三种

// 公共权限 public      成员 类内可以访问 类外可以访问

// 保护权限 protected   成员 类内可以访问 类外不可以访问 子类可以访问保护内容(继承)

// 私有权限 private     成员 类内可以访问 类外不可以访问 子类不可以访问私有内容

class Person {
  public:
    string mName;

  protected:
    string mCar;

  private:
    string mPasswd;
};