/*
#面试刷题# 第122期
#Leetcode# Q0005 最长的回文子串
难度：中
给定一个字符串s，在s中找到最长的palindromic子串，可以假设s的最大长度为1000。

示例1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

示例2:
Input: "cbbd"
Output: "bb"
*/
#include "leetcode.h"

namespace q0005
{

template<typename T>
bool run_testcases() {
    T slt;
    CHECK_RET(("bab" == slt.longestPalindrome("babad"))
        ||("aba" == slt.longestPalindrome("babad")));
    CHECK_RET("bb" == slt.longestPalindrome("cbbd"));
    return true;
}

// Time Limit Exceeded
class Solution {
private:
bool _isPalindrome(std::string & s, int start, int end){
	while(s[start]==s[end]){
		start += 1;
		end -=1;
		if(end <= start){return true;} 
	}
	return false;
}
public:
    string longestPalindrome(string s) {
        int maxlen = 1000;
        int size = s.size();
        int max_s = 0, max_e = 0;
        for(int si = 0; si < size; si++){
            for(int ei = 0; ei < maxlen; ei++){
                int end = si + ei;
                if (end >= size){break;}
                if (_isPalindrome(s, si, end)){
                    if((end-si) > (max_e-max_s)){
                        max_s = si;
                        max_e = end;
                    }
                }
            }
        }
        return s.substr(max_s, max_e-max_s+1);
    }
};
TEST(Q0005, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

/*
动态规划: https://leetcode.com/problems/longest-palindromic-substring/discuss/633843/C%2B%2B-DP-solution
*/
// Runtime: 768 ms, faster than 8.80% 
// Memory Usage: 16.5 MB, less than 34.48%
class Solution02 {
    public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (0 == len) {return "";}
        int ret_idx = 0, ret_len = 1;
        // create dp table
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // for strings with length=1
        for (int i = 0; i < len; ++i) {dp[i][i] = true;}
        // for strings with length=2
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ret_idx = i;
                ret_len = 2;
            }
        }
        // for string with length in [3, len]
        for (int n = 3; n <= len; ++n) {
            for (int i = 0; i <= len - n; ++i) {
                int j = i + n -1;
                if (s[i] == s[j]) {dp[i][j] = dp[i+1][j-1];}
                if (dp[i][j]) {ret_idx = i; ret_len = n;}
            }
        }
        return s.substr(ret_idx, ret_len);
    }
};    
TEST(Q0005, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
} // namespace q0005

