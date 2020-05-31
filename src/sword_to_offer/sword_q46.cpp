
/*
#剑指Offer# Q46 求1+2+...+n


*/
#include "leetcode.h"

namespace sword_q46
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/* 总体而言，这个题目很没意思
思路1: 使用构造函数累计静态属性，创建n个对象
思路2: 利用虚函数的多态求解，父类的成员函数负责终止，子类的成员函数负责累计，用两元素数组实现，本质上仍然是递归。
思路3: 利用具有相同签名的函数指针来实现
*/

class Solution {
public:
    void func();
};

} // namespace sword_q46
