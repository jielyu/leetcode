/*
#面试刷题# 第68期
#Leetcode# Q1373 二叉树中的最大BST总和
难度：高
给定二叉树的root，任务是返回也是二叉搜索树（BST）的任何子树的所有键的最大和。
假设BST定义如下：
(1) 节点的左子树仅包含键值小于节点键值的节点。
(2) 节点的右子树仅包含键大于该节点的键的节点。
(3) 左和右子树都必须也是二叉制搜索树。
约束条件：
每棵树最多有40000个节点。
每个节点的值在[-4 * 10^4，4 * 10^4]之间。

例1:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

例2:
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

例3:
Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.

例4:
Input: root = [2,1,3]
Output: 6

例5:
Input: root = [5,4,8,3,null,6,3]
Output: 7
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
    bool _check_bst(TreeNode * root, int & max_sum) {
        if (!root) {return true;}
        // mark current node
        bool is_bst = true;
        if (root->left && root->val <= root->left->val) {
            is_bst = false;
        }
        if (root->right && root->val >= root->right->val) {
            is_bst = false;
        }
        // check children
        auto is_left = _check_bst(root->left, max_sum);
        auto is_right = _check_bst(root->right, max_sum);
        // sum
        if (is_bst && is_left && is_right) {
            if (root->left) {
                root->val += root->left->val;
            }
            if (root->right) {
                root->val += root->right->val;
            }
            if (root->val > max_sum) {
                max_sum = root->val;
            }
            return true;
        }
        return false;
    }
    
public:
    // Runtime: 188 ms, faster than 89.77%
    // Memory Usage: 64.3 MB, less than 100.00%
    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        _check_bst(root, max_sum);
        return max_sum;
    }
};