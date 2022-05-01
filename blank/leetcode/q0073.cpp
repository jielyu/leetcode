
/*
#LeetCode# Q0073 矩阵置零
难度：中

给定一个m×n的矩阵，如果一个元素为0，则把它的整个行和列都设为0，在原地执行。

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

跟进：

使用O(mn)空间的直截了当的解决方案可能是个坏主意。
简单的改进是使用O(m+n)空间，但仍然不是最好的解。
能否设计出一个常数空间的解法？
可以接受

*/
#include "leetcode.h"

namespace q0073
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

} // namespace q0073
