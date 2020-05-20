/*
#面试刷题# 第123期
#LeetCode# Q1446 连续字符
难度：低
给定一个字符串s，该字符串的幂是一个非空子串的最大长度，其中只包含一个唯一字符。
返回该字符串的幂。
约束条件：
1 <= s.length <= 500
s 由小写英文字母组成

示例1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

示例2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

示例3:
Input: s = "triplepillooooow"
Output: 5

示例4:
Input: s = "hooraaaaaaaaaaay"
Output: 11

示例5:
Input: s = "tourist"
Output: 1
*/
#include "leetcode.h"

namespace q1446
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(2 == slt.maxPower("leetcode"));
    CHECK_RET(5 == slt.maxPower("abbcccddddeeeeedcba"));
    CHECK_RET(5 == slt.maxPower("triplepillooooow"));
    CHECK_RET(11 == slt.maxPower("hooraaaaaaaaaaay"));
    CHECK_RET(1 == slt.maxPower("tourist"));

    return true;
}

// Runtime: 16 ms, faster than 38.95%
// Memory Usage: 7 MB, less than 100.00%
class Solution {
public:
    int maxPower(string s) {
        const int MAX_NUM = 26, len = s.size();
        int ret = 1, idx = 0;
        vector<int> letters(MAX_NUM, 0);
        ++letters[s[0] - 'a'];
        for (int i = 1; i < len; ++i) {
            idx = s[i] - 'a';
            if (s[i] == s[i-1]) {
                ++letters[idx];
                if (letters[idx] > ret) {ret = letters[idx];}
            } else {
                letters[s[i-1] - 'a'] = 0;
                letters[idx] = 1;
            }
        }
        return ret;
    }
};    
TEST(Q1446, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 8 ms, faster than 85.75%
// Memory Usage: 7 MB, less than 100.00%
class SolutionZY {
public:
    int maxPower(string s) {
        const int MAX_NUM = 26;
        int ret = 1, idx = 0;
        vector<int> letters(MAX_NUM, 0);
        ++letters[s[0]-'a'];
        int i = 1;
        while (i < s.size()) {
            idx = s[i] - 'a';
            if (s[i] == s[i-1]) {
                ++letters[idx];
                if (letters[idx] > ret) {ret = letters[idx];}
                i++;
            } else {
                letters[s[i-1]-'a']=0;
                letters[idx] = 1;
                i++;
            }
        }
        return ret;
    }
};
TEST(Q1446, SolutionZY) {EXPECT_TRUE(run_testcases<SolutionZY>());}
} 
// namespace q1446