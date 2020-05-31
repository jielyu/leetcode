/*
#剑指Offer# Q06 重建二叉树
根据先序遍历和中序遍历重建二叉树

*/
#include "leetcode.h"

namespace sword_q06
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> preorder {1,2,4,7,3,5,6,8}, inorder{4,7,2,1,5,3,8,6};
        auto root = slt.constructBinaryTree(preorder, inorder);
        vector<int> ret_preorder, ret_inorder;
        get_preorder(root, ret_preorder);
        get_inorder(root, ret_inorder);
        delete_tree(root);
        CHECK_RET(comp_vector(ret_preorder, preorder) 
                      && comp_vector(ret_inorder, inorder));
    }

    return true;
}

class Solution {
private:
    TreeNode * _construct(int pre_start, int pre_end, int in_start, int in_end, 
                              vector<int> & preorder, vector<int> & inorder) {
        // 先序遍历的第一个元素就是根节点
        TreeNode * root = new TreeNode(preorder[pre_start]);
        // 叶子结点
        if (pre_start == pre_end) {
            if (in_start == in_end && preorder[pre_start] == inorder[in_start]) {
                return root;
            } else {
                throw "Invalid";
            }
        }
        // 在中序遍历中查找根节点
        int root_idx = in_start;
        while(root_idx <= in_end && inorder[root_idx] != preorder[pre_start]) {++root_idx;}
        if (root_idx == in_end && preorder[pre_start] != inorder[root_idx]) {
            throw "Invalid";
        }
        // 重建左子树
        int left_len = root_idx - in_start;
        if (left_len > 0) {
            root->left = _construct(pre_start+1, pre_start+left_len, 
                                       in_start, root_idx-1, preorder, inorder);
        }
        // 重建右子树
        if (left_len < pre_end - pre_start) {
            root->right = _construct(pre_start + left_len + 1, pre_end,
                                         root_idx + 1, in_end, preorder, inorder);
        }
        return root;
    }

public: 
    TreeNode * constructBinaryTree(vector<int> & preorder, vector<int> & inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {return nullptr;}
        return _construct(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
    }
};
TEST(SwordQ06, Solution){EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q06