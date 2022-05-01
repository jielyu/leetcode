
/*
#剑指Offer# Q23 从上到下打印二叉树
从上到下打印二叉树的每一个节点，同一层的节点按照从左到右的顺序打印

这个是二叉树的层次遍历，需要引入一个队列

*/
#include "leetcode.h"

namespace sword_q23
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
public:
    vector<int> printTop2Bottom(TreeNode * root) {
        vector<int> ret;
        deque<TreeNode*> deq;
        deq.push_back(root);
        while (deq.size()) {
            auto node = deq.front();
            deq.pop_front();
            ret.push_back(node->val);

            if (node->left) {deq.push_back(node->left);}
            if (node->right) {deq.push_back(node->right);}
        }
        return ret;
    }
};

} // namespace sword_q23
