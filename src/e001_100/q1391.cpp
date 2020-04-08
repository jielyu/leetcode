/*
#面试刷题# 第77期
#Leetcode# Q1391 检查网格中是否存在有效路径
难度：中
给定一个m x n的网格。 网格的每个单元代表一条街道。 网格[i] [j]的街道可以是：
1，表示连接左单元格和右单元格的街道。
2表示连接上层单元和下层单元的街道。
3，表示连接左单元格和下部单元格的街道。
4，表示连接右单元格和下单元格的街道。
5，表示连接左单元格和上单元格的街道。
6表示连接右单元格和上单元格的街道。
最初，您将从左上单元格（0,0）的街道开始。 网格中的有效路径是从左上单元格（0,0）开始到右下单元格（m-1，n-1）结束的路径。 路径只能沿着街道行驶。

请注意，您不得更改任何街道。

如果网格中存在有效路径，则返回true；否则返回false。
约束条件：
m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6

例1：
Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).

例2:
Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)

例3:
Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).

例4:
Input: grid = [[1,1,1,1,1,1,3]]
Output: true

例5:
Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true
*/

/*
提示：深度优先搜索每个方向。
*/

#include "leetcode.h"

namespace q1391{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

// Runtime: 192 ms, faster than 72.48%
// Memory Usage: 53.5 MB, less than 100.00%
class Solution {
private:
    // UP->RIGHT->DOWN->LEFT
    vector<vector<int>> relate = {{0, 1, 0, 1}, 
                                  {1, 0, 1, 0}, 
                                  {0, 0, 1, 1}, 
                                  {0, 1, 1, 0}, 
                                  {1, 0, 0, 1}, 
                                  {1, 1, 0, 0}};
    vector<vector<int>> directions = {{-1, 0},
                                      {0, 1},
                                      {1, 0},
                                      {0, -1}};
    
    // check whether two streets can connect with each other
    bool _check_conn(int i, int j, int dir) {
        return relate[i][dir] && relate[j][(dir+2)%4];
    }
    
    bool _dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> & used) {
        if (i == grid.size()-1 && j == grid[0].size()-1) {
            return true;
        }
        if (!used[i][j]) {
            used[i][j] = true;
            // check all directions
            int new_i = 0, new_j = 0;
            for (int k = 0; k < 4; ++k) {
                new_i = i + directions[k][0];
                new_j = j + directions[k][1];
                // check index range
                if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size()) {
                    if (_check_conn(grid[i][j]-1, grid[new_i][new_j]-1, k)) {
                        if (_dfs(grid, new_i, new_j, used)) {
                            //cout << i << "," << j << "," << new_i << "," << new_j << endl;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));
        return _dfs(grid, 0, 0, used);
    }
};

};
