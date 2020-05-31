
/*
#剑指Offer# Q25 二叉树中和为某一值的路径
输入一棵二叉树和一个整数，打印处二叉树中节点只的和为给定整数的所有路径。
从树的根节点开始往下一直到叶子节点所经过的所有节点形成的路径。

*/
#include "leetcode.h"

namespace sword_q25
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
private:
    void _find(TreeNode * root, int target, int & sum, 
                   vector<int> & path, vector<vector<int>> & ret) {
        sum += root->val;
        path.push_back(root->val);
        // 对于叶子节点
        if ((!root->left) && (!root->right) && (sum == target)) {ret.push_back(path);}
        // 不是叶子节点
        if (root->left) {_find(root->left, target, sum, path, ret);}
        if (root->right) {_find(root->right, target, sum, path, ret);}
        // 返回父节点时清除之前的状态
        sum -= root->val;
        path.pop_back();
    }

public:
    vector<vector<int>> findPath(TreeNode * root, int target) {
        vector<vector<int>> ret;
        if (!root) {return ret;}
        vector<int> path;
        int sum = 0;
        _find(root, target, sum, path, ret);
        return ret;
    }
};

} // namespace sword_q25
