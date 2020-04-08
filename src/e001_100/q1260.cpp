/*
#面试刷题# 第0055期
#Leetcode# Q1260 平移2D网格
难度：低
给定大小为m x n和整数k的2D grid。您需要将网格移动k次。
在一次换档操作中：
(1) grid[i] [j]处的元素移至grid[i] [j +1]。
(2) grid[i] [n-1]的元素移至grid[i +1] [0]。
(3) grid[m-1] [n-1]的元素移至grid[0] [0]。
应用移位操作k次后，返回2D网格。
约束条件：
(a) m == grid.length
(b) n == grid[i].length
(c) 1 <= m <= 50
(d) 1 <= n <= 50
(e) -1000 <= grid[i][j] <= 1000
(f) 0 <= k <= 100

例1：
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

例2:
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

例3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
*/
#include "leetcode.h"

namespace q1260{

template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        vector<vector<int>> grid{{1,2,3},{4,5,6},{7,8,9}};
        int k = 1;
        vector<vector<int>> ret{{9,1,2},{3,4,5},{6,7,8}};
        if (!comp_matrix(slt.shiftGrid(grid,k), ret)) {return false;}
    }

    // example 02
    {
        vector<vector<int>> grid{{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
        int k = 4;
        vector<vector<int>> ret{{12,0,21,13},{3,8,1,9},{19,7,2,5},{4,6,11,10}};
        if (!comp_matrix(slt.shiftGrid(grid,k), ret)) {return false;}
    }

    // example 03
    {
        vector<vector<int>> grid{{1,2,3},{4,5,6},{7,8,9}};
        int k = 9;
        vector<vector<int>> ret{{1,2,3},{4,5,6},{7,8,9}};
        if (!comp_matrix(slt.shiftGrid(grid,k), ret)) {return false;}
    }

    return true;
}

class Solution {
public:
    // Runtime: 68 ms, faster than 76.29%
    // Memory Usage: 13.4 MB, less than 100.00%
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        int ii = 0, jj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                jj = (j+k) % n;
                ii = i + (j+k) / n; 
                ii %= m;
                ret[ii][jj] = grid[i][j];
            }
        }
        return ret;
    }
};
TEST(Q1260, Solution) {EXPECT_EQ(q1260::run_testcases<Solution>(), true);}

};