
/*
#剑指Offer# Q13 在O(1) 的时间内删除节点

这道题的关键思路是吧下一个节点复制到当前要删除的节点，然后再删除下一个节点。

知道了思路其他都很简单。

但是在实际使用中，我们常常需要先查找出删除节点的位置，然后才知道要删除谁，
但是这道题的情况是直接给定需要删除节点的指针，所以才有可能在O(1)的时间复杂度下完成。

*/
#include "leetcode.h"

namespace sword_q13
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
public:
    void func();
};

} // namespace sword_q13
