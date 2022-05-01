
/*
#LeetCode# Q0026 从排序阵列中删除重复内容
难度：低
给出一个排序数组nums，在原地删除重复的元素，使每个元素只出现一次，并返回新的长度。

不要为另一个数组分配额外的空间，必须用O(1)个额外的内存就地修改输入数组。

澄清：

疑惑为什么返回的值是整数，而你的答案是数组？

注意，输入数组是通过引用传递进来的，这意味着对输入数组的修改也会被调用者知道。

内部你可以这样想：
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

*/
#include "leetcode.h"

namespace q0026
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

} // namespace q0026
