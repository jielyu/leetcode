
/*
#LeetCode# Q0099 修复二叉搜索树
难度：高

二叉搜索树（BST）的两个元素被错误交换。

恢复树而不更改其结构。

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

跟进：

使用O（n）空间的解决方案非常简单。
您能设计一个不变的空间解决方案吗？

*/
#include "leetcode.h"

namespace q0099 
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

} // namespace q0099
