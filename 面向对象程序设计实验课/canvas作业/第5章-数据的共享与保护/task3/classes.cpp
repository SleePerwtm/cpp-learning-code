class X;

class Y {
  public:
    void g(X* x);
};

class Z {
  public:
    void f(X* x);
};

void h(X* x);

class X {
    friend void Y::g(X* x); // 声明类方法为友元
    friend class Z;         // 声明类为友元
    friend void h(X* x);    // 声明全局函数为友元

  public:
    // 设值函数
    void set_i(int i) { i_ = i; }

    // 取值函数
    int get_i() const { return i_; }

  private:
    int i_;
};

void Y::g(X* x) {
    x->i_++; // 对i_进行+1操作
}

void Z::f(X* x) {
    x->i_ += 5; // 对i_进行+5操作
}

void h(X* x) {
    x->i_ += 10; // 对i_进行+10操作
}