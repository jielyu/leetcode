/*
#面试刷题# 第121期
#Leetcode# Q0003 无重复字符的最长子串
难度：中
给定一个字符串，求出不重复字符的最长子串的长度。

示例1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

示例2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

示例3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include "leetcode.h"

namespace q0003
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(3 == slt.lengthOfLongestSubstring("abcabcbb"));
    CHECK_RET(1 == slt.lengthOfLongestSubstring("bbbbb"));
    CHECK_RET(3 == slt.lengthOfLongestSubstring("pwwkew"));

    return true;
}
/*
采用滑动窗口的方法，最重要的是抓住调整起始位置的时机。
可以用数组记录字符的上一次出现的位置，当然也可以用map。
对于有经验的人来说可能是一道简单题，但是对于初学者可能还是有些困难，关键在于滑动窗口这个思路。
*/
// Runtime: 8 ms, faster than 94.59% 
// Memory Usage: 7.6 MB, less than 100.00%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ret = 0;
        const int NUM_LETTERS = 128;
        // to store last position of current char
        vector<int> last_pos(NUM_LETTERS, -1);
        int start = 0, end = 0, idx = 0;
        for (; end < n; ++end) {
            idx = last_pos[s[end]];
            // meet repeated letter in sliding window
            if (idx >= start && idx <= end) {
                start = idx + 1;
            }
            last_pos[s[end]] = end;

            //cout << "start=" << start << ", end=" << end << endl;
            if (end - start + 1 > ret) {ret = end - start + 1;}
        }
        return ret;
    }
};
TEST(Q0003, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q0003
