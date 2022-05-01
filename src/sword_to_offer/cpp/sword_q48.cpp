
/*
#剑指Offer# Q48 不能被继承的类
用C++设计一个不能被继承的类。


*/
#include "leetcode.h"

namespace sword_q48
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
思路1: 将构造函数设置为私有
思路2:利用虚继承一个辅助类，而这个辅助类的构造函数是私有的，不过其友元声明为当前类。
*/

class Solution {
public:
    void func();
};

} // namespace sword_q48
