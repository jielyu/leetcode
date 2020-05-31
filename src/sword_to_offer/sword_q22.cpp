
/*
#剑指Offer# Q22 栈的压入和弹出序列
输入两个整数序列，第一个序列表示栈的眼熟顺序，请判断第二序列是否为该栈的弹出序列。
假设压入栈的所有数字都不相等。


*/
#include "leetcode.h"

namespace sword_q22
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> seq1 {1,2,3,4,5}, seq2{4,5,3,2,1};
        CHECK_RET(true == slt.isStackOrder(seq1, seq2));
    }

    {
        vector<int> seq1 {1,2,3,4,5}, seq2{4,3,5,1,2};
        CHECK_RET(false == slt.isStackOrder(seq1, seq2));
    }

    return true;
}

class Solution {
public:
    bool isStackOrder(vector<int> & seq1, vector<int> & seq2) {
        int len = seq1.size();

        stack<int> buffer;
        buffer.push(seq1[0]);
        int idx1 = 1; //用于表示seq1的遍历进度
        for (int idx2 = 0; idx2 < len; ++idx2) {
            while (idx1 < len && seq2[idx2] != buffer.top()) {
                buffer.push(seq1[idx1]);
                ++idx1;
            }
            // cout << "idx1=" << idx1 << endl;
            if (seq2[idx2] == buffer.top()) {buffer.pop();}
        }
        return buffer.size() == 0;
    }
};
TEST(SwordQ22, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q22
