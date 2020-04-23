/*
#面试刷题# 第0102期
#Leetcode# Q1415 长度为n的所有快乐字符串的第k个词典序的字符串
难度：中
一个快乐的字符串是一个字符串，它是由
仅由集合[''a', 'b', 'c']中的字母组成。
s[i] != s[i + 1] 对于所有的i的值从1到s.length - 1之间的值（字符串是1个索引）。
例如，字符串 "abc"，"ac"，"b "和 "abcbabcbcbcb "都是快乐的字符串，
而字符串 "aa"，"baa "和 "abababbc "不是快乐的字符串。
给定两个整数n和k，考虑一个按词法顺序排序的长度为n的所有快乐字符串的列表。
如果长度为n的快乐字符串少于k，则返回该列表中的第k个字符串，或者返回一个空字符串。
约束条件：
1 <= n <= 10
1 <= k <= 100

示例1:
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

示例2:
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.

示例3:
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"

示例4:
Input: n = 2, k = 7
Output: ""

示例5:
Input: n = 10, k = 100
Output: "abacbabacb"
*/
#include "leetcode.h"

namespace q1415 {

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%
class Solution {
public:
    string getHappyString(int n, int k) {
        // 第一个字母有3种选择，其他字母都只有两种选择。
        // 总的情况个数为3*2^(n-1)
        int t = 3;
        for (int i = 1; i < n; ++i) {
            t <<= 1;
        }
        if (k > t) {return "";}
        // create each char in the answer string
        string letters = "abc", ret;
        int count = 0, idx = 0;
        for (int i = 0; i < n; ++i) {
            if (0 == i) { // for the first char
                t /= 3;
            } else { // for the others
                t >>= 1;
            }
            // count bits
            for (count = 0; k > t; ++count) {k -= t;};
            // find index
            for (idx = 0; (ret != "" && ret.back() == letters[idx]) || (count--); ++idx);
            ret.push_back(letters[idx]);
        }
        return ret;
    }
};
} // namespace q1415