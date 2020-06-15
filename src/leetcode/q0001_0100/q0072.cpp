
/*
#LeetCode# Q0072 编辑距离
难度：高

给出两个单词word1和word2，求出将word1转换为word2所需的最小操作数。

你可以对一个单词进行以下3个操作。

插入一个字符
删除一个字符
替换一个字符

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/
#include "leetcode.h"

namespace q0072
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 16 ms, faster than 58.55%
// Memory Usage: 8.9 MB, less than 56.65%
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        // 两个字符串都是空的状态
        dp[0][0] = 0;
        // 第一个字符串为空的状态
        for (int i = 1; i <= len2; ++i) {dp[0][i] = i;}
        // 第二个字符串为空的状态
        for (int i = 1; i <= len1; ++i) {dp[i][0] = i;}
        // 处理两个字符串都不为空的状态
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                // 当前字符相同，则保持上一个状态
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                // 当前字符不相同，则取最短距离
                } else {
                    // 插入：1 + dp[i][j-1]
                    // 删除：1 + dp[i-1][j]
                    // 替换：1 + dp[i-1][j-1]
                    dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};

} // namespace q0072
