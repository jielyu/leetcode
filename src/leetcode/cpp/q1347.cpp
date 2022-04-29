/*
#面试刷题# 第0029期
#Leetcode# Q1347 制作两个字符串错序的最小步骤数
难度： 中
给定两个相等大小的字符串s和t。在一个步骤中，您可以选择t的任何字符并将其替换为另一个字符。
返回使t成为错序字符串的最小步数。
字符串的Anagram是包含相同字符且具有不同（或相同）顺序的字符串。
约束条件：
(a) 1 <= s.length <= 50000
(b) s.length == t.length
(c) s 和 t 由小写英文字母构成

例1:
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

例2:
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

例3:
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 

例4:
Input: s = "xxyyzz", t = "xxyyzz"
Output: 0

例5:
Input: s = "friend", t = "family"
Output: 4
*/
#include "leetcode.h"

namespace q1347{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    CHECK_RET(1 == slt.minSteps("bab", "aba"));
    CHECK_RET(5 == slt.minSteps("leetcode", "practice"));
    CHECK_RET(0 == slt.minSteps("anagram", "mangaar"));
    CHECK_RET(0 == slt.minSteps("xxyyzz", "xxyyzz"));
    CHECK_RET(4 == slt.minSteps("friend", "family"));

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 120 ms, faster than 40.00%
    // Memory Usage: 19.1 MB, less than 100.00%
    int minSteps(string s, string t) {
        unordered_map<char, int> dict;
        for (auto & v : s) {
            ++dict[v];
        }
        for (auto & v : t) {
            --dict[v];
        }
        int sum = 0;
        for (auto & kv : dict) {
            if (kv.second < 0) {
                sum += kv.second;
            }
        }
        return abs(sum);
    }
};
TEST(Q1347, Solution) {EXPECT_TRUE(q1347::run_testcases<q1347::Solution>());}

class Solution02 {
public:
    // Runtime: 84 ms, faster than 94.93%
    // Memory Usage: 18.9 MB, less than 100.00%
    int minSteps(string s, string t) {
        int dict[26] = {0};
        for (auto & v : s) {
            ++dict[v - 'a'];
        }
        for (auto & v : t) {
            --dict[v - 'a'];
        }
        int sum = 0;
        for (auto & kv : dict) {
            if (kv < 0) {
                sum += kv;
            }
        }
        return abs(sum);
    }
};
TEST(Q1347, Solution02) {EXPECT_TRUE(q1347::run_testcases<q1347::Solution02>());}
};