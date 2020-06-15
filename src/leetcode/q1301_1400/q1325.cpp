/*
#面试刷题# 第0024期
#Leetcode# Q1325 删除具有给定值的叶子
难度：中
给定二叉树root和整数target，请删除所有具有值target的叶节点。
请注意，一旦删除具有值target的叶节点，如果它的父节点成为叶节点并具有值target，则也应将其删除（您必须继续这样做，直到不能这样做）。
约束条件：
(a) 1 <= target <= 1000
(b) 每棵树最多有 3000 个节点.
(c) 每个节点所存储值的范围 [1, 1000].

例1:
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).

例2:
Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]

例3:
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.

例4:
Input: root = [1,1,1], target = 1
Output: []

例5:
Input: root = [1,2,3], target = 1
Output: [1,2,3]
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

namespace q1325{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}
class Solution {
public:
    // Runtime: 24 ms, faster than 60.16%
    // Memory Usage: 21.7 MB, less than 100.00%
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // for null pointer
        if (!root) {
            return NULL;
        }
        // for left and right children
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        // for leaf nodes
        if ((!root->left) && (!root->right)) {
            if (root->val == target) {
                //delete root;
                return NULL;
            }
        }
        return root;
    }
};

};
