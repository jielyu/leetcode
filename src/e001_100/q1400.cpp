/*
#面试刷题# 第0085期
#Leetcode# Q1400 构造K回文字符串
难度：中
给定字符串s和整数k。 您应该使用s中的所有字符构造k个非空回文字符串。
如果可以使用s中的所有字符构造k个回文字符串，则返回True，否则返回False。
约束条件：
1 <= s.length <= 10^5
所有字符都是小写英文字母
1 <= k <= 10^5

示例1:
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

示例2:
Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

示例3:
Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

示例4:
Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.

示例5:
Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
*/


// Runtime: 56 ms, faster than 42.86%
// Memory Usage: 11.8 MB, less than 100.00%
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {return false;}
        const int MAX_NUM = 26;
        bitset<26> tab;
        for (auto & c : s) {
            tab[(int)(c-'a')].flip();
        };
        return tab.count() <= k;
    }
};

// Runtime: 52 ms, faster than 42.86%
// Memory Usage: 11.9 MB, less than 100.00%
class Solution01 {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {return false;}
        const int MAX_NUM = 26;
        bool tab[MAX_NUM] = {false};
        for (auto & c : s) {
            tab[(int)(c-'a')] = !tab[(int)(c-'a')];
        };
        for (int i = 0; i < MAX_NUM; ++i) {
            if (tab[i]) {
                --k;
            }
        }
        return k >= 0;
    }
};