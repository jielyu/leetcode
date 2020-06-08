
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Runtime: 40 ms, faster than 42.83%
// Memory Usage: 53.6 MB, less than 30.22%
class Solution {
private:
    TreeNode * first, * second, * prev;
    void _inorder(TreeNode * root) {
        if (nullptr == root) {return;}
        // 遍历左子树
        _inorder(root->left);
        // 处理跟节点
        if (nullptr == first && prev->val > root->val) {
            first = prev;
        }
        if (first && prev->val > root->val) {
            second = root;
        }
        // 记录已经遍历的最大值的节点
        prev = root;
        // 遍历右子树
        _inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        
        TreeNode tmp(INT_MIN);
        prev = &tmp;
        // 中序遍历找到两个元素
        _inorder(root);
        // 交换
        if (first && second) {
            int mid = first->val;
            first->val = second->val;
            second->val = mid;
        }
    }
};

} // namespace q0099
