
/*
#剑指Offer# Q24 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后续遍历的结果。
如果是，则返回true；否则返回false。假设数组数字各不相同。

*/
#include "leetcode.h"

namespace sword_q24
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> seq {5,7,6,9,11,10,8};
        CHECK_RET(true == slt.isPostOrder(seq));
    }

    {
        vector<int> seq {7, 4, 6, 5};
        CHECK_RET(false == slt.isPostOrder(seq));
    }

    return true;
}

class Solution {
private:
    bool _check(vector<int> & seq, int low, int high) {
        if (low > high) {return true;}
        int root = seq[high];
        // 找到左子树的根节点
        int left_idx = low;
        for (;left_idx < high; ++left_idx) {if (seq[left_idx] > root){break;}}
        // 检查右子树
        int right_idx = left_idx;
        for (;right_idx < high; ++right_idx) {if (seq[right_idx] < root) {return false;}}
        // 递归判断左子树
        bool left = true;
        if (left_idx > low) {left = _check(seq, low, left_idx - 1);}
        // 递归判断右子树
        bool right = true;
        if (left_idx < high) {right = _check(seq, left_idx, high-1);}
        return left && right;
    }

public:
    bool isPostOrder(vector<int> & seq) {
        int len = seq.size();
        return _check(seq, 0, len-1);
    }
};
TEST(SwordQ24, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q24
