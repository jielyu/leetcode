/*
#面试刷题# 第0113期
#Leetcode# Q0102 按层次顺序遍历二叉树
给定一个二叉树，返回其节点值的级别顺序遍历。即，从左到右，逐级递进）。

示例：
Input: [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/
#include "leetcode.h"

namespace q0102
{
template<typename T>
bool run_testcases() {
    T slt;
}

// Runtime: 4 ms, faster than 94.38% 
// Memory Usage: 12.5 MB, less than 100.00%
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {return ret;}
        vector<int> mid;
        // create a queue to store children nodes
        queue<TreeNode*> buff;
        buff.push(root);
        while (buff.size() > 0) {
            mid.clear();
            // traversal nodes with the same level
            for (int i = buff.size(); i > 0; --i) {
                auto * node = buff.front(); buff.pop();
                mid.push_back(node->val);
                // add child nodes to the buff
                if (node->left) {buff.push(node->left);}
                if (node->right) {buff.push(node->right);}
            }
            ret.push_back(mid);
        }
        return ret;
    }
};
} // namespace q0102

