/*
#面试刷题# 第67期
#Leetcode# Q1382 平衡二叉搜索树
难度：中
给定二叉搜索树，请返回具有相同节点值的平衡二叉制搜索树。
当且仅当每个节点的两个子树的深度相差不超过1时，二叉搜索树才会达到平衡。
如果答案不只一个，请返回其中一个。
约束条件：
(a) 树中的节点数在1到10^4之间。
(b) 树节点将具有1到10^5之间的不同值。

例1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
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
namespace q1382{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
private:
    void _inorder(TreeNode * root, vector<int> & arr) {
        if (!root) {return;}
        _inorder(root->left, arr);
        arr.push_back(root->val);
        _inorder(root->right, arr);
    }
    
    TreeNode * _create_balance(vector<int> & arr, int low, int high) {
        if (low > high) {return nullptr;}
        int mid = (high + low) / 2;
        auto root = new TreeNode(arr[mid]);
        root->left = _create_balance(arr, low, mid-1);
        root->right = _create_balance(arr, mid+1, high);
        return root;
    }
    
public:
    // Runtime: 180 ms, faster than 56.71%
    // Memory Usage: 52.1 MB, less than 100.00%
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        _inorder(root, arr);
        return _create_balance(arr, 0, arr.size()-1);
    }
};

};
