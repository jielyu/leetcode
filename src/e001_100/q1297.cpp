/*
#面试刷题# 第0050期
#Leetcode# Q1297 子字符串的最大出现次数
难度：中
给定字符串s，请根据以下规则返回任何子字符串的最大出现次数：
(1) 子字符串中唯一字符的数量必须小于或等于maxLetters。
(2) 子字符串的大小必须介于minSize和maxSize（含）之间。
约束条件：
(a) 1 <= s.length <= 10^5
(b) 1 <= maxLetters <= 26
(c) 1 <= minSize <= maxSize <= min(26, s.length)
(d) s只包含小写英文字母

例1:
Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

例2:
Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.

例3:
Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3

例4:
Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0
*/
#include "leetcode.h"

namespace q1297{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        string s = "aababcaab";
        int maxLetters = 2, minSize = 3, maxSize = 4;
        if (2 != slt.maxFreq(s, maxLetters, minSize, maxSize)) {return false;}
    }

    {
        string s = "aaaa";
        int maxLetters = 1, minSize = 3, maxSize = 3;
        if (2 != slt.maxFreq(s, maxLetters, minSize, maxSize)) {return false;}
    }

    {
        string s = "aabcabcab";
        int maxLetters = 2, minSize = 2, maxSize = 3;
        if (3 != slt.maxFreq(s, maxLetters, minSize, maxSize)) {return false;}
    }

    {
        string s = "abcde";
        int maxLetters = 2, minSize = 3, maxSize = 3;
        if (0 != slt.maxFreq(s, maxLetters, minSize, maxSize)) {return false;}
    }

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 92 ms, faster than 68.21%
    // Memory Usage: 23.7 MB, less than 100.00%
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> str_dict;
        unordered_map<char, int> char_dict;
        int len = s.size();
        // begin of sliding window
        int low = 0, high = 0;
        for (; high < minSize && high < len; ++high) {
            ++char_dict[s[high]];
        }
        // slide window on the string
        string substring;
        while(len - low >= minSize) {
            // record substring satisfied conditions
            if (char_dict.size() <= maxLetters) {
                substring = s.substr(low, high - low);
                ++str_dict[substring];
            }
            // move low index
            --char_dict[s[low]];
            if (char_dict[s[low]] == 0) {
                char_dict.erase(s[low]);
            }
            // move high index
            ++low;
            ++char_dict[s[high]];
            ++high;
        }
        // select string with the maximum number
        int max_cnt = 0;
        for (auto & p : str_dict) {
            // cout << p.first << "," << p.second << endl;
            if (p.second > max_cnt) {
                max_cnt = p.second;
            }
        }
        return max_cnt;
    }
};
TEST(Q1297, Solution) {EXPECT_EQ(q1297::run_testcases<q1297::Solution>(), true);}
};