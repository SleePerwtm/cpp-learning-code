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
    friend void Y::g(X* x);
    friend class Z;
    friend void h(X* x);

  public:
    void set_i(int i) { i_ = i; }
    int get_i() const { return i_; }

  private:
    int i_;
};

void Y::g(X* x) { x->i_++; }

void Z::f(X* x) { x->i_ += 5; }

void h(X* x) { x->i_ += 10; }