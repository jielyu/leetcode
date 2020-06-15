/*
#面试刷题# 第0047期
#Leetcode# Q1302 最深的叶子总和
给定二叉树，返回其最深叶的值之和。
约束条件：
树中的节点数在1到10^4之间。
节点的值在1到100之间。

例1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "leetcode.h"

namespace q1302{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // get depth of the tree
    int get_depth(TreeNode* root, int d) {
        if (!root || (!root->left && !root->right)) {
            return d;
        }
        return max(get_depth(root->left, d+1), get_depth(root->right, d+1));
    }
    
    // calculate the sum of the deepest leaves
    void sum_deepest_leaves(TreeNode* root, int & sum, int d, const int & max_d) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right && d == max_d) {
            sum += root->val;
        }
        sum_deepest_leaves(root->left, sum, d+1, max_d);
        sum_deepest_leaves(root->right, sum, d+1, max_d);
    }
    // Runtime: 52 ms, faster than 52.77%
    // Memory Usage: 31.4 MB, less than 100.00%
    int deepestLeavesSum(TreeNode* root) {
        int max_d = get_depth(root, 1);
        int sum = 0;
        sum_deepest_leaves(root, sum, 1, max_d);
        return sum;
    }
    
    // get all leaves and their depth
    int get_leaves(TreeNode* root, vector<vector<int>> & leaves, int d) {
        if (!root) {
            return d;
        }
        if (!root->left && !root->right) {
            leaves.push_back({root->val, d});
            return d;
        }
        return max(get_leaves(root->left, leaves, d+1), get_leaves(root->right, leaves, d+1));
    }
    
    // Runtime: 60 ms, faster than 14.98%
    // Memory Usage: 36.6 MB, less than 100.00%
    int deepestLeavesSum_2(TreeNode* root) {
        // get all leaves and the depth of tree
        vector<vector<int>> leaves;
        auto max_d = get_leaves(root, leaves, 1);
        // calculate the sum of deepest leaves
        int sum = 0;
        for (auto & leaf : leaves) {
            if (leaf[1] == max_d) {
                sum += leaf[0];
            }
        }
        return sum;
    }
};

};
