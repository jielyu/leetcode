/*
#面试刷题# 第125期
#LeetCode# Q1448 计算二叉树中的好节点
难度：中
给定一个二进制树的根，如果在从根到X的路径中没有值大于X的节点，则树中的节点X被命名为好。
返回二进制树中的好节点的数量。
约束条件：
二进制树中的节点数在[1，10^5]范围内。
每个节点的值在[-10^4，10^4]之间。

示例1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

示例2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

示例3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
*/
#include "leetcode.h"

namespace q1448
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

// Runtime: 332 ms, faster than 41.41%
// Memory Usage: 86.4 MB, less than 100.00%
class Solution {
private:
    void _dfs(TreeNode* root, int max_val, int & ret) {
        if (nullptr == root) {return;}
        if (root->val >= max_val) {
            ++ret;
            max_val = root->val;
        }
        _dfs(root->left, max_val, ret);
        _dfs(root->right, max_val, ret);
    }
public:
    int goodNodes(TreeNode* root) {
        int ret = 0;
        _dfs(root, -100000, ret);
        return ret;
    }
};    
} // namespace q1448
