
/*
#LeetCode# Q0010 正则表达式匹配
难度：高
给定一个输入字符串(s)和一个模式(p)，实现正则表达式匹配，支持'.'和'*'。

'.' 匹配任何单个字符。
'*' 匹配前面的零个或多个元素。
匹配应该覆盖整个输入字符串（而不是局部）。

注意：:
s可以是空的，并且只包含小写字母a-z。
p可以是空的，只包含小写字母a-z，以及像.或*这样的字符。

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
#include "leetcode.h"

namespace q0010
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(true == slt.isMatch("aab", "c*a*b"));

    return true;
}

/*
思路：动态规划。关键在于模式为*的递推公式
*/

// Runtime: 8 ms, faster than 75.59%
// Memory Usage: 6.6 MB, less than 100.00%
class Solution {
public:
    bool isMatch(string s, string p) {
        if ("*" == p) {return true;}
        int len_s = s.size(), len_p = p.size();
        vector<vector<bool>> dp(len_s+1, vector<bool>(len_p+1, false));
        // 空字符串与模式的匹配
        dp[0][0] = true;
        for (int i = 2; i <= len_p; ++i) {
            dp[0][i] = (p[i-1] == '*') && dp[0][i-2];
        }
        // 非空字符串匹配
        for (int i = 1; i <= len_s; ++i) {
            for (int j = 1; j <= len_p; ++j) {
                // 字符相等，或者点号匹配
                if (s[i-1]==p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    auto b1 = (s[i-1] == p[j-2]) && dp[i-1][j];
                    auto b2 = (p[j-2] == '.') && dp[i-1][j];
                    dp[i][j] = dp[i][j-2] || b1 || b2;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[len_s][len_p];
    }
};
TEST(Q0010, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q0010
