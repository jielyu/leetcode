/*
#面试刷题# 第0106期
#Leetcode# Q1422 分开一个字符串后的最大得分
难度：低
给定一个由0和1组成的字符串s，返回将字符串拆分成两个非空的子串（即左子串和右子串）后的最大得分。
分割一个字符串后的分数是左边子串中的零数加上右边子串中的1。
约束条件：
2 <= s.length <= 500
字符串s仅由'0'和'1'组成。

示例1:
Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

示例2:
Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

示例3:
Input: s = "1111"
Output: 3
*/
#include "leetcode.h"

namespace q1422
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(5 == slt.maxScore("011101"));
    CHECK_RET(5 == slt.maxScore("00111"));
    CHECK_RET(3 == slt.maxScore("1111"));

    return true;
}

// Runtime: 0 ms, faster than 100.00% 
// Memory Usage: 6.4 MB, less than 100.00%
class Solution {
public:
    int maxScore(string s) {
        // counter the number of ones
        int digit_cnt[2] = {0};
        for (auto & c : s) { digit_cnt[(int)('1' == c)]++;}
        // search all possible
        int n = s.size() - 1, ret = 0, sum = 0;
        digit_cnt[0] = 0;
        for (int i = 0; i < n; ++i) {
            '1' == s[i] ? digit_cnt[1]-- : digit_cnt[0]++;
            sum = digit_cnt[1] + digit_cnt[0];
            if (sum > ret) {
                ret = sum;
            }
        }
        return ret;
    }
};
TEST(Q1422, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1422

