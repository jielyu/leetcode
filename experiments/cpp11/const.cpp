#include <iostream>

using namespace std;

class A {
public:
    int data;
    int * p_data;
    explicit A(): data(123) {
        p_data = & data;
    }

    // 
    //explicit A(const A & a) {
    //     _data = a._data + 1;
    // }
    void print() const {
        cout << "Hello:" << data << endl;
    }
};

int main() {

    const A a1;
    // 编译器会进行内存拷贝，指针变量也是拷贝变量本身，而不是所指对象
    A a2 = a1;
    // 这一行语句会修改a1中的成员变量data
    *(a1.p_data) = 1;
    // 以下语句编译会报错
    //a1.data = 99;
    // 这一句会修改a1中的成员变量 data
    *(a2.p_data) = 12;

    a1.print();
    a2.print();
    
    // 测试常量、指针常量、和常量指针的操作
    const int * p_xx = new int(11);
    const int xx = 12;
    const int * p = &xx;
    int * const p_x = const_cast<int *>(p);
    *(p_x) = 1;
    cout << (*p_xx) << endl;
    cout << (xx) << endl;

    return 0;
}