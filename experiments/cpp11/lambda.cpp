#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
用于测试C++11中匿名函数的完整语法
*/
void grammar() {
    cout << "grammar test:" << endl;
    int a = 1, b= 2;

    // 以值传递的方式利用外部值
    auto func = [=]() mutable throw() -> int {
        int ret = a + b; 
        a += 1;
        return ret; 
    };
    int ret = func();
    cout << "a=" << a << ", ret=" << ret << endl; 
    ret = func();
    cout << "a=" << a << ", ret=" << ret << endl; 

    // 以引用的方式利用外部值
    auto func2 = [&]() mutable throw() -> int {
        int ret = a + b; 
        a += 1;
        return ret; 
    };
    ret = func2();
    cout << "a=" << a << ", ret=" << ret << endl; 
}

/*
用于测试匿名函数的默认使用情况
*/ 
void default_format() {
    cout << "default format test:" << endl;
    int ret = [](int x, int y) {return x + y;}(1, 2);
    cout << ret << endl;
}

void print(const vector<int> & arr) {
    for (auto i : arr) {
        cout << i << ",";
    }
    cout << endl;
}

/*
测试匿名函数的与STL结合的使用方法
*/
void stl_func() {
    cout << "combinate with STL:" << endl;
    vector<int> arr {5,3,2,6,8,9,7};
    std::sort(arr.begin(), arr.end());
    print(arr);

    std::sort(arr.begin(), arr.end(), [](int x, int y) {return x > y;});
    print(arr);
}

/*
测试匿名函数嵌入的情况
*/
void lambda_embed() {
    cout << "embedding lambda test:" << endl;
    int a = 1, b = 2;
    int ret = [=]() {
            return a + [=](){
                    return b * b;
                }();
        }();
    cout << ret << endl;
}

int main() {
    grammar();
    default_format();
    stl_func();
    lambda_embed();
    return 0;
}