/*
#面试刷题# 第0098期
#Leetcode# Q1254 封闭岛屿数
难度：中
给定的2D grid由0（土地）和1（水）组成。 孤岛是最大的4向连接的0，并且封闭的孤岛是完全由1包围的孤岛（所有左，上，右，下）。
返回封闭的岛数。
约束条件：
1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

示例1:
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

示例2:
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

示例3:
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
*/
#include "leetcode.h"

namespace q1254 {


template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        vector<vector<int>> grid{{1,1,1,1,1,1,1,0},
                                 {1,0,0,0,0,1,1,0},
                                 {1,0,1,0,1,1,1,0},
                                 {1,0,0,0,0,1,0,1},
                                 {1,1,1,1,1,1,1,0}};
        int ret = 2;
        CHECK_RET(slt.closedIsland(grid) == ret);
    }

    // example 02
    {
        vector<vector<int>> grid{{0,0,1,0,0},
                                 {0,1,0,1,0},
                                 {0,1,1,1,0}};
        int ret = 1;
        CHECK_RET(slt.closedIsland(grid) == ret);
    }

    // example 03
    {
        vector<vector<int>> grid{{1,1,1,1,1,1,1},
                                 {1,0,0,0,0,0,1},
                                 {1,0,1,1,1,0,1},
                                 {1,0,1,0,1,0,1},
                                 {1,0,1,1,1,0,1},
                                 {1,0,0,0,0,0,1},
                                 {1,1,1,1,1,1,1}};
        int ret = 2;
        CHECK_RET(slt.closedIsland(grid) == ret);
    }

    return true;
}

// Runtime: 12 ms, faster than 77.46% 
// Memory Usage: 7.4 MB, less than 100.00% 
class Solution {
private:
    // define four directions
    vector<vector<int>> _dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void _dfs(vector<vector<int>> & grid, int i, int j) {
        // out of range or meet water
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()
               || 1 == grid[i][j]) {return;}
        // mark (i,j)
        grid[i][j] = 1;
        // search four directions
        for (int k = 0; k < 4; ++k) {
            _dfs(grid, i + _dirs[k][0], j + _dirs[k][1]);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ret = 0;
        int m = grid.size(), n = grid[0].size();
        // remove island in boundary
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == i || m-1 == i || 0 == j || n-1 == j) {
                    _dfs(grid, i, j);
                }
            }
        }
        
        // find closed island
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // meet land
                if (0 == grid[i][j]) {
                    _dfs(grid, i, j);
                    ++ret;
                }
            }
        }
        return ret;
    }
};
TEST(Q1254, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

};
