/*
#面试刷题# 第0023期
#Leetcode# Q1328 打破回文
难度：中
给定回文字符串 palindrome，请使用任何小写英文字母精确替换一个字符，以使该字符串成为按字典顺序最小的不是回文的字符串。
这样做之后，返回最终字符串。如果没有办法，返回空字符串。
约束条件：
(a) 1 <= palindrome.length <= 1000
(b) palindrome 只由小写英文字母组成.

例1:
Input: palindrome = "abccba"
Output: "aaccba"

例2:
Input: palindrome = "a"
Output: ""
*/

class Solution {
public:
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 8.5 MB, less than 100.00%
    string breakPalindrome(string palindrome) {
        int len = palindrome.size();
        // for empty string
        if (len <= 1) {
            return string();
        }
        // change a letter to 'a' which is not 'a' originally 
        for (int i=0; i<len; ++i) {
            if (i == len-i-1) {
                continue;
            }
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // for all 'a' string
        palindrome[len-1] = 'b';
        return palindrome;
    }
};