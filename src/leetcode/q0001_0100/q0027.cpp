
/*
#LeetCode# Q0027 移除元素
难度：低

给出一个数组nums和一个值val，就地删除该值的所有实例，并返回新的长度。

不要为另一个数组分配额外的空间，必须用O(1)个额外的内存原地修改输入数组。

元素的顺序是可以改变的。在新的长度之外留什么都无所谓。

例子1.给定nums=[3,2]。

给定nums = [3,2,2,2,3], val = 3,

你的函数应该返回长度=2，nums的前两个元素是2。

在返回的长度之外留下什么并不重要。
例子2.给定nums = [0,1,2,2,2,3,0,4

给定nums = [0,1,2,2,2,2,3,0,4,2], val = 2,

你的函数应该返回length = 5，其中前五个元素的nums包含0、1、3、0和4。

注意，这五个元素的顺序可以是任意的。

在返回的长度之外设置什么值并不重要。
澄清：

疑惑为什么返回的值是整数，而你的答案是数组？

注意，输入数组是通过引用传递进来的，这意味着对输入数组的修改也会被调用者知道。

内部你可以这样想：
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
#include "leetcode.h"

namespace q0027
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

} // namespace q0027
