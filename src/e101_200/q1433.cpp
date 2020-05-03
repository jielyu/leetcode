/*
#面试刷题# 第111期
#Leetcode# Q1433 检查一个字符串是否可以断掉另一个字符串
难度：中
给定两个大小相同的字符串：s1和s2，检查字符串s1的某些变换是否可以打破字符串s2的某些变换，反之亦然（换句话说，s2可以打破s1）。
如果x[i]>=y[i](按字母顺序)，对于0到n-1之间的所有i，一个字符串x可以打破字符串y(都是n的大小)。
约束条件：
s1.length ==n
s2.length ==n
1 <= n <= 10^5
所有的字符串都由小写英文字母组成。

示例1:
Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".

示例2:
Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.

示例3:
Input: s1 = "leetcodee", s2 = "interview"
Output: true
*/
#include "leetcode.h"

namespace q1433
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(true == slt.checkIfCanBreak("abc", "xya"));
    CHECK_RET(false == slt.checkIfCanBreak("abe", "acd"));
    CHECK_RET(true == slt.checkIfCanBreak("leetcodee", "interview"));

    return true;
}

// Runtime: 416 ms, faster than 20.00%
// Memory Usage: 11.5 MB, less than 100.00%
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int len = s1.size();
        bool ret_gte = true, ret_lte = true;
        for (int i = 0; i < len; ++i) {
            if (s1[i] < s2[i]) {ret_gte = false;}
            if (s1[i] > s2[i]) {ret_lte = false;}
            if (!(ret_gte || ret_lte)) {return false;}
        }
        return ret_gte || ret_lte;
    }
};
TEST(Q1433, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 96 ms, faster than 100.00%
// Memory Usage: 11.7 MB, less than 100.00%
class Solution02 {
private:
    bool _check_valid(vector<int> freq, const string & s) {
        int idx = 0;
        for (const auto & c : s) {
            idx = (int)(c - 'a');
            for (; idx < 26; ++idx) {
                // 抵消一个不小于 c 的字符
                if (freq[idx] > 0) {
                    --freq[idx];
                    break;
                }
            }
            if (idx >= 26) {return false;}
        }
        return true;
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        for (auto & c : s1) {freq1[c-'a']++;}
        for (auto & c : s2) {freq2[c-'a']++;}
        return _check_valid(freq1, s2) || _check_valid(freq2, s1);
    }
};
TEST(Q1433, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
} // namespace q1433
