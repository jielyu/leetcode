
/*
#剑指Offer# Q19 二叉树的镜像
编写一个函数，输入一棵二叉树，输出其镜像。


*/
#include "leetcode.h"

namespace sword_q19
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
public:
    TreeNode * mirror(TreeNode * root) {
        if (!root) {return nullptr;}
        if ((!root->left) && (!root->right)) {return root;}
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if (root->left) {mirror(root->left);}
        if (root->right) {mirror(root->right);}
        return root;
    }
};

} // namespace sword_q19
