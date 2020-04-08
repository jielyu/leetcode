/*
#面试刷题# 第0061期
#Leetcode# Q1379 在该树的克隆中找到二叉树的对应节点
难度：中
给定两个树original和cloned，并给出对原始树中节点target的引用。
cloned树是original树的副本。
返回对cloned树中相同节点的引用。
请注意，不允许您更改两个树或target节点中的任何一个，并且答案必须是对cloned树中节点的引用。
后续措施：如果允许在树上重复值，则解决问题。
约束条件：
(a) 树中的节点数在[1，10^4]范围内。
(b) 树的节点的值是唯一的。
(c) target节点是original树中的节点，并且不为null。

例1:
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

例2:
Input: tree = [7], target =  7
Output: 7

例3:
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4

例4:
Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
Output: 5

例5:
Input: tree = [1,2,null,3], target = 2
Output: 2
*/
#include "leetcode.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

namespace q1379{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    
    // Runtime: 528 ms, faster than 70.00%
    // Memory Usage: 167.5 MB, less than 100.00%
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // check empty pointer
        if ((!original) || (!cloned)) {
            return nullptr;
        }
        // check current root node
        if (original->val == target->val) {
            return cloned;
        }
        // check left child tree
        auto left = getTargetCopy(original->left, cloned->left, target);
        if (left) {
            return left;
        }
        // check right child tree
        auto right = getTargetCopy(original->right, cloned->right, target);
        if (right) {
            return right;
        }
        // cannot find target
        return nullptr;
    }
};

};
