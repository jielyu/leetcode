/*
#面试刷题# 第0045期
#Leetcode# Q1305 两个二叉搜索树中的所有元素
难度：中
给定两个二叉搜索树root1和root2。
返回一个列表，其中包含两个树中所有以升序排序的整数。
约束条件：
(a) 每棵树最多有5000个节点。
(b) 每个节点的值在[-10 ^ 5，10 ^ 5]之间。

例1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

例2:
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

例3:
Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

例4:
Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

例5:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
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

#include <iostream>
#include <vector>
#include <stddef.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void get_by_inorder(TreeNode* root, vector<int> & vec) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            vec.push_back(root->val);
            return;
        }
        get_by_inorder(root->left, vec);
        vec.push_back(root->val);
        get_by_inorder(root->right, vec);
        return;
    }
    
    // Runtime: 280 ms, faster than 60.84%
    // Memory Usage: 59.3 MB, less than 100.00%
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2, vec;
        // get values from binary tree by inorder
        get_by_inorder(root1, vec1);
        get_by_inorder(root2, vec2);
        // merge vector by ascending
        int len1 = vec1.size(), len2 = vec2.size();
        vec.reserve(len1 + len2);
        int i1 = 0, i2 = 0;
        while (i1 < len1 && i2 < len2) {
            if (vec1[i1] < vec2[i2]) {
                vec.push_back(vec1[i1]);
                ++i1;
            } else {
                vec.push_back(vec2[i2]);
                ++i2;
            }
        }
        while(i1 < len1) {
            vec.push_back(vec1[i1]);
            ++i1;
        }
        while(i2 < len2) {
            vec.push_back(vec2[i2]);
            ++i2;
        }
        return vec;
    }
};