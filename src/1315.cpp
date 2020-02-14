/*
#面试刷题# 第0036期
#Leetcode# Q1315 具有偶值祖父母的节点总数
难度：中
给定一个二叉树，返回具有偶值祖父母的节点的值之和。 
（如果存在，则节点的祖父母是其父代的父代。）
如果没有节点具有偶数值的祖父母，则返回0。
约束条件：
(a) 树中的节点数在1到10 ^ 4之间。
(b) 节点的值在1到100之间。

例1:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
*/
#include <iostream>
#include <stddef.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Runtime: 44 ms, faster than 91.00%
    // Memory Usage: 31.7 MB, less than 100.00%
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if ((!root->left) && (!root->right)) {
            return 0;
        }
        // for even number in the root
        if (root->val % 2 == 0) {
            int num = 0;
            if (root->left) {
                if (root->left->left) {
                    num += root->left->left->val;
                }
                if (root->left->right) {
                    num += root->left->right->val;
                }
            }
            if (root->right) {
                if (root->right->left) {
                    num += root->right->left->val;
                }
                if (root->right->right) {
                    num += root->right->right->val;
                }
            }
            return num + sumEvenGrandparent(root->left) \
                + sumEvenGrandparent(root->right);
        }
        return sumEvenGrandparent(root->left) \
                + sumEvenGrandparent(root->right);
    }
};