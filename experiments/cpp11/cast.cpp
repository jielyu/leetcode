#include <iostream>

using namespace std;

int func() {return 1.2;}

void implicit_cast() {
    cout << "implicit cast:" << endl;
    int p = 1.2; // 赋值转换
    double q = 1 + 1.2; // 算数运算的转换
    int k = func(); // 返回值类型转换
    cout << p << "," << q << "," << k << endl;
}

void force_cast() {
    cout << "force cast:" << endl;
    int x = (int)(1.2+2.3);
    cout << x << endl;
}

void sta_cast() {
    cout << "static_cast:" << endl;
    int x = static_cast<int>(1.2 + 2.3);
    cout << x << endl;
}

class A {
public:
    virtual void func(){}
};
class B : public A {
public:
    void func2() {}
};

void dyn_func(A * a) {
    B * b = dynamic_cast<B*>(a);
    cout << b << endl;
    b->func2();
}

void dyn_cast() {
    cout << "dynamic cast:" << endl;
    A * a = new A;
    B * b = dynamic_cast<B*>(a);
    cout << b << endl;

    B * bb = new B;
    dyn_func(bb);

    delete a;
    delete bb;
}

void rein_cast() {
    cout << "reinterpret cast: do not use it" << endl;
}

class C {
public:
    int x = 0;
};

void con_cast() {
    cout << "const cast:" << endl;

    const int x = 12;
    int * p = const_cast<int *>(&x);
    *p = 10; 
    cout << x << ", " << (*p) << endl;

    const int * xx = new int(12);
    int * pp = const_cast<int*>(xx);
    // *xx = 1; // 编译报错：ead-only variable is not assignable
    *pp = 10;
    cout << *xx << ", " << *pp << endl;

    const C c1;
    C & c2 = const_cast<C&>(c1);
    c2.x = 2;
    cout << c1.x << "," << c2.x << endl;

    const C & c3 = C();
    C & c4 = const_cast<C&>(c3);
    c4.x = 2;
    cout << c3.x << "," << c4.x << endl; 
}

int main() {
    implicit_cast();
    force_cast();
    sta_cast();
    dyn_cast();
    rein_cast();
    con_cast();
    return 0;
}