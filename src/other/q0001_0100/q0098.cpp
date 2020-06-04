
/*
#LeetCode# Q0098 验证二进制搜索树
难度：中

给定一个二叉树，请确定它是否为有效的二叉树（BST）。

假设BST定义如下：

节点的左子树仅包含键值小于节点键值的节点。
节点的右子树仅包含键大于该节点的键的节点。
左子树和右子树都必须也是二进制搜索树。

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

*/
#include "leetcode.h"

namespace q0098
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

} // namespace q0098
