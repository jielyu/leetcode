
/*
#LeetCode# Q0075 颜色排序
难度：中
给出一个有n个对象的数组，其中有n个对象的颜色为红色、白色或蓝色，将它们就地排序，使相同颜色的对象相邻，颜色顺序为红、白、蓝。

这里，我们将使用整数0、1和2分别代表红色、白色和蓝色。

注意：在这个问题上，你不需要使用库中的排序函数。

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

跟进：

一个比较直接的解决方法是用计数排序的两遍算法。
首先迭代数组计数数组中的0、1、2的数组，然后用0的总数覆盖数组，再覆盖1的数组，然后再覆盖2的数组。
你能不能想出一个只用常数空间的单次通过算法？
*/
#include "leetcode.h"

namespace q0075
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

} // namespace q0075
