/*
#面试刷题# 第0020期
#Leetcode# Q1332 删除回文序列
给定一个仅由字母“ a”和“ b”组成的字符串s。您只需一步即可从中删除一个回文子序列。
返回使给定字符串为空的最小步骤数。
字符串是给定字符串的子序列，如果它是通过删除给定字符串的某些字符而不更改其顺序而生成的。
如果一个字符串向后和向前读取相同，则称为回文。
约束条件：
(a) 0 <= s.length <= 1000
(b) s 只由字母 'a' 和 'b'组成

例1:
Input: s = "ababa"
Output: 1
Explanation: String is already palindrome

例2:
Input: s = "abb"
Output: 2
Explanation: "abb" -> "bb" -> "". 
Remove palindromic subsequence "a" then "bb".

例3:
Input: s = "baabb"
Output: 2
Explanation: "baabb" -> "b" -> "". 
Remove palindromic subsequence "baab" then "b".

例4:
Input: s = ""
Output: 0
*/
#include "leetcode.h"
namespace q1332{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 4 ms, faster than 69.11% 
    // Memory Usage: 8.5 MB, less than 100.00%
    int removePalindromeSub(string s) {
        // for empty string
        int len = s.size();
        if (len == 0) {
            return 0;
        }
        // return 2 for non-palindromic and 1 for palindromic
        int low = 0, high = len - 1;
        while (low < high) {
            if (s[low++] != s[high--]) {
                return 2;
            }
        }
        return 1;
    }
};

};