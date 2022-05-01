/*
#剑指Offer# Q04 替换空格
编写一个函数将数输入的字符串中的每个空格替换成“%20”。
*/
#include "leetcode.h"

namespace sword_q04
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        string i = "We are happy.", ret = "We%20are%20happy.";
        CHECK_RET(ret == slt.replaceBlank(i)); 
    }

    return true;
}

/*时间复杂度O(n)*/
class Solution {
public:
    string replaceBlank(string & str) {
        int len = str.size();
        if (!len) {return "";}
        // 计数空格的数量
        int blank_cnt = 0;
        for (auto c : str) {if (' ' == c) {++blank_cnt;}}
        // 计算新字符串应有的长度
        int n_len = len + blank_cnt * 2;
        string ret(n_len, '0');
        // 从尾部到头部开始替换
        int old_idx = len - 1, new_idx = n_len - 1;
        while (old_idx >= 0) { // 原位替换可加上条件“new_idx > old_idx”
            if (str[old_idx] == ' ') {
                ret[new_idx--] = '0';
                ret[new_idx--] = '2';
                ret[new_idx--] = '%';
            } else {
                ret[new_idx--] = str[old_idx];
            }
            --old_idx;
        }
        return ret;
    }
};
TEST(SwordQ04, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

} // namespace sword_q04
