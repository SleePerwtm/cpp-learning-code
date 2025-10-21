#include <iostream>

class Base {
  public:
    int mA;

  protected:
    int mB;

  private:
    int mC;
};

// 公共继承会继承所有公共成员与保护成员，不改变其访问权限，私有成员不会被继承
class Inherited1 : public Base {
  public:
    void func() {
        mA = 10;
        mB = 20;
        // mC = 30; // 私有成员不能被继承
    }
};

void test1() {
    Inherited1 obj;
    obj.mA = 5;
    // obj.mB = 15; // 保护成员不能被访问
}

// 保护继承会继承所有公共成员与保护成员，均继承为保护成员，私有成员不会被继承
class Inherited2 : protected Base {
  public:
    void func() {
        mA = 10;
        mB = 20;
        // mC = 30; // 私有成员不能被继承
    }
};

void test2() {
    Inherited2 obj;
    // obj.mA = 5; // 保护继承后公共成员被转换为保护成员
    // obj.mB = 15;
}

// 私有继承会继承所有公共成员与保护成员，均继承为私有成员，私有成员不会被继承
class Inherited3 : private Base {
  public:
    void func() {
        mA = 10;
        mB = 20;
        // mC = 30; // 私有成员不能被继承
    }
};

class Inherited4 : public Inherited3 {
  public:
    void func() {
        // mA = 10; //
        // 表明Inherited3的mA通过私有继承以后变为私有成员，无法再被继承
    }
};