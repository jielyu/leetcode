
/*
#LeetCode# Q0015 三数之和
难度：中

给定一个数组nums的n个整数，nums中是否有元素a, b, c，这样a + b + c = 0？找出数组中所有唯一的三连数，并给出0的和。

注意：在数组中不能包含重复的元素a、b、c。

解集不能包含重复的三连数。

示例：
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
#include "leetcode.h"

namespace q0015
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
思路：固定一个，然后用两个指针分别从首尾搜索另完两个，不过需要先排序，注意一个数字在同一位置只能使用一次
*/

class Solution {
public:
    void func();
};

} // namespace q0015
