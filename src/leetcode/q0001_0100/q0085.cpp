
/*
#面试刷题# 第128期
#LeetCode# Q0085 最大矩形
难度：高
给定一个填充有0和1的2D二进制矩阵，找到仅包含1的最大矩形，并返回其面积。

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

*/
#include "leetcode.h"

namespace q0085
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 68 ms, faster than 24.39%
// Memory Usage: 13.5 MB, less than 7.27%
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {return 0;}
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<pair<int, int>>> dp(m+1, vector<pair<int, int>>(n+1, {0,0}));
        vector<vector<int>> dp_row (m+1, vector<int>(n+1, 0));
        vector<vector<int>> dp_col (m+1, vector<int>(n+1, 0));
        int ret = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('1' == matrix[i][j]) {
                    // 记录行列的当前状态
                    dp_row[i+1][j+1] = 1 + dp_row[i+1][j];
                    dp_col[i+1][j+1] = 1 + dp_col[i][j+1];
                    // 记录当前状态
                    dp[i+1][j+1].first = 1 + min(dp[i][j].first, dp_row[i+1][j]);
                    dp[i+1][j+1].second = 1 + min(dp[i][j].second, dp_col[i][j+1]);
                    
                    auto & p = dp[i+1][j+1];
                    // 单行
                    if (dp_row[i+1][j+1] > p.first * p.second ) {
                        p.first = dp_row[i+1][j+1];
                        p.second = 1;
                    }
                    // 单列
                    if (dp_col[i+1][j+1] > p.first * p.second) {
                        p.first = 1;
                        p.second = dp_col[i+1][j+1];
                    }
                    // 记录最大面积
                    if (ret < p.first * p.second) {
                        ret = p.first * p.second;
                    }
                }
            }
        }
        return ret;
    }
};

} // namespace q0085
