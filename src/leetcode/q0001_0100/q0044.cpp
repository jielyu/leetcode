
/*
#LeetCode# Q0044 通配卡匹配
难度：高
给定一个输入字符串(s)和模式(p)，实现通配符模式匹配，支持'?'和'*'。

'?' 匹配任何单个字符。
'*' 匹配任何字符序列（包括空序列）。
匹配应该覆盖整个输入字符串（而不是局部）。

注意：'*'?

s可以是空的，只包含小写字母a-z。
p可以是空的，只包含小写字母a-z，以及像 ? 或 * 这样的字符。

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
#include "leetcode.h"

namespace q0044
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 232 ms, faster than 26.78%
// Memory Usage: 11.1 MB, less than 51.86%
class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        vector<vector<bool> > dp(len_s + 1, vector<bool>(len_p + 1, false));
        // 设置空字符串与当前模式的匹配状态
        dp[0][0] = true;
        for (int i = 1; i <= len_p; ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        // 处理非空字符串与模式的匹配
        for (int i = 1; i <= len_s; ++i) {
            for (int j = 1; j <= len_p; ++j) {
                if (s[i-1] == p[j-1] || '?' == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if ('*' == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[len_s][len_p];
    }
};

} // namespace q0044
