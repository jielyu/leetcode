
/*
#LeetCode# Q0062 唯一路径
难度：中

一个机器人位于m×n网格的左上角（下图中标有 "开始"）。

该机器人在任何时间点上只能向下或向右移动。机器人正试图到达网格的右下角（下图中标有 "完成"）。

有多少个可能的唯一路径？

约束：
1 <= m，n <= 100
可以保证答案小于或等于2*10^9。

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28


*/
#include "leetcode.h"

namespace q0062
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 33.75%
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {dp[i][0] = 1;}
        for (int j = 1; j < n; ++j) {dp[0][j] = 1;}
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

} // namespace q0062
