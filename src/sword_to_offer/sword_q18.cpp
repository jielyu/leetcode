
/*
#剑指Offer# Q18 树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构。


*/
#include "leetcode.h"

namespace sword_q18
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
private:
    bool _check_sub_tree(TreeNode * root1, TreeNode * root2){
        if (!root2) {return true;}
        if (!root1) {return false;}
        if (root1->val != root2->val) {return false;}
        // 对比对应的左子树和右子树
        return _check_sub_tree(root1->left, root2->left) 
                   && _check_sub_tree(root1->right, root2->right);
    }
public:
    bool hasSubTree(TreeNode * root1, TreeNode * root2) {
        bool ret = false;
        if (root1->val == root2->val) {
            // 检查以root1为根节点的树是否包含以root2为根节点的树
            ret = _check_sub_tree(root1, root2);
        }
        // 检查左子树
        if (!ret) {hasSubTree(root1->left, root2);}
        // 检查右子树
        if (!ret) {hasSubTree(root1->right, root2);}
        return ret;
    }
};

} // namespace sword_q18
