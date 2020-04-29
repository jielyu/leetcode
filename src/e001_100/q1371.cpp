/*
#面试刷题# 第70期
#Leetcode# Q1371 查找包含偶数个元音的最长子串
难度：中
给定字符串s，返回包含每个元音的偶数次的最长子字符串的大小。
也就是说，“ a”，“ e”，“ i”，“ o”和“ u”必须出现偶数次。
约束条件：
(a) 1 <= s.length <= 5 x 10^5
(b) s仅包含小写英文字母

例1:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

例2:
Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

例3:
Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
*/
#include "leetcode.h"

namespace q1371{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    CHECK_RET(13 == slt.findTheLongestSubstring("eleetminicoworoep"));
    CHECK_RET(5 == slt.findTheLongestSubstring("leetcodeisgreat"));
    CHECK_RET(6 == slt.findTheLongestSubstring("bcbcbc"));

    // succ
    return true;
}

class Solution {
public:

    // 关键思路：异或操作可用于“偶数个”要求
    // Runtime: 76 ms, faster than 93.29%
    // Memory Usage: 16.2 MB, less than 100.00%
    int findTheLongestSubstring(string s) {
        vector<int> idx_vec(0x01<<6, -1);
        int len = s.size(), mask = 0, ret = 0;
        for (int i = 0; i < len; ++i) {
            switch(s[i]) {
                case 'a': mask ^= 0x01 << 1;break;
                case 'e': mask ^= 0x01 << 2;break;
                case 'i': mask ^= 0x01 << 3;break;
                case 'o': mask ^= 0x01 << 4;break;
                case 'u': mask ^= 0x01 << 5;
                //default: mask ^= 0x01;
            }
            if (-1 == idx_vec[mask] && mask) {
                idx_vec[mask] = i;
            } else {
                ret = max(ret, i - idx_vec[mask]);
            }
            //cout << i << "," << mask << "," << idx_vec[mask] << endl;
        }
        return ret;
    }
};
TEST(Q1371, Solution) {EXPECT_TRUE(q1371::run_testcases<q1371::Solution>());}
};
