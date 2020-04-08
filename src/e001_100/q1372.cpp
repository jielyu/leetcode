/*
#面试刷题# 第69期
#Leetcode# Q1372 二叉树中最长的锯齿形路径
难度：中
给定二进制树的root，二进制树的ZigZag路径定义如下：
(1) 选择二叉树中的任何节点和方向（右或左）。
(2) 如果当前方向正确，则移至当前节点的右子级，否则移至左子级。
(3) 从右向左或从右向左更改方向。重复第二和第三步，直到无法在树中移动。
(4) 之字形长度定义为访问的节点数-1。（单个节点的长度为0）。
返回该树中包含的最长的锯齿形调整浪路径。
约束条件：
(a) 每棵树最多有50000个节点。
(b) 每个节点的值在[1，100]之间。

例1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

例2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

例3:
Input: root = [1]
Output: 0
*/
#include "leetcode.h"

namespace q1373{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

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
    
    void _get_nodes(TreeNode * root, vector<TreeNode*> & non_leaf_nodes) {
        if (!root) {return;}
        //if ((!root->left) && (!root->right)) {return;}
        non_leaf_nodes.push_back(root);
        _get_nodes(root->left, non_leaf_nodes);
        _get_nodes(root->right, non_leaf_nodes);
    }
    
    int _count_zigzag(TreeNode * root, bool is_left) {
        if (!root) {return 0;}
        // count left child tree
        if (is_left && root->left) {
            return 1 + _count_zigzag(root->left, !is_left);
        // count right child tree
        } else if ((!is_left) && root->right) {
            return 1 + _count_zigzag(root->right, !is_left);
        }
        return 1;
    }
    
public:
    // Time Limit Exceeded	
    int longestZigZag(TreeNode* root) {
        // get all nodes which are not leaves
        vector<TreeNode*> non_leaf_nodes;
        _get_nodes(root, non_leaf_nodes);
        // check all non-leaf nodes
        int ret = 1, left = 0, right = 0;
        for (auto node : non_leaf_nodes) {
            // check left child tree
            left = _count_zigzag(node, true);
            // check right child tree
            right = _count_zigzag(node, false);
            // record max length
            ret = left > right ? max(ret, left) : max(ret, right);
            // cout << node->val << "," << left << "," << right << endl;
        }
        return ret - 1;
    }
};

class Solution02 {
private:
    void traversal(TreeNode * root, bool is_left, int len, int & max_len) {
        if (!root) {return;}
        if (len > max_len) {
            max_len = len;
        }
        traversal(root->left, true, is_left ? 1 : len+1, max_len);
        traversal(root->right, false, is_left ? len+1 : 1, max_len);
    }
    
public:
    // Runtime: 196 ms, faster than 56.51%
    // Memory Usage: 53.2 MB, less than 100.00%
    int longestZigZag(TreeNode* root) { 
        int max_len = 0;
        traversal(root, true, 0, max_len);
        return max_len;
    }
};

};
