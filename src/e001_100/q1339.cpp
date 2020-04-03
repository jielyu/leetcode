/*
#面试刷题# 第0017期
#Leetcode# Q1339 分裂二叉树的最大乘积
难度：中
给定二叉树的root。通过删除1个边，将二叉树分成两个子树，以使子树之和的乘积最大化。
由于答案可能太大，请以10 ^ 9 + 7为模返回。
约束条件：
(a) 每棵树的节点数量在[2,50000]范围内
(b) 每棵树存储的值在[1,10000]范围内

例1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
例2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
例3:
Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025
例4:
Input: root = [1,1]
Output: 1
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
class Solution {
private:
    int _total_sum(TreeNode * root) {
        if (!root) {
            return 0;
        }
        root->val += _total_sum(root->left);
        root->val += _total_sum(root->right);
        return root->val;
    }
    
    long _find_max_prod(TreeNode * root, const int & total) {
        if ((!root->left) && (!root->right)) {
            return 0;
        }
        long left = 0, right = 0;
        if (root->left) {
            left = (long)(root->left->val) * (total - root->left->val);
            left = max(left, _find_max_prod(root->left, total));
        }
        if (root->right) {
            right = (long)(root->right->val) * (total - root->right->val);
            right = max(right, _find_max_prod(root->right, total));
        }
        return max(left, right);
    }
    
public:
    // Runtime: 160 ms, faster than 76.35% 
    // Memory Usage: 68.8 MB, less than 100.00%
    int maxProduct(TreeNode* root) {
        int total = _total_sum(root);
        long ret = _find_max_prod(root, total);
        return ret % (1000000000 + 7);
        
    }
};