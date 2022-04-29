
/*
#LeetCode# Q0064 最小路径总和
难度：中

给定一个由非负数组成的m x n网格，从左上角到右下角，找出一条从左上角到右下角的路径，使所有数字之和最小化。

注意：在任何时间点上，你只能向下或向右移动。

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/
#include "leetcode.h"

namespace q0064
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 20 ms, faster than 27.98%
// Memory Usage: 9.8 MB, less than 24.72%
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (0 == m || 0 == n) {return 0;}
        // 行累计
        for (int i = 1; i < n; ++i) {grid[0][i] += grid[0][i-1];}
        // 列累计
        for (int i = 1; i < m; ++i) {grid[i][0] += grid[i-1][0];}
        // 最短距离记录
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
} // namespace q0064
