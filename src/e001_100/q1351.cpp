/*
#面试刷题# 第0056期
#Leetcode# Q1351 计数排序矩阵中的负数
难度：低
给定一个m * n矩阵grid，该grid按行和列均以非递增顺序排序。
返回grid中的负数。
约束条件：
(a) m == grid.length
(b) n == grid[i].length
(c) 1 <= m, n <= 100
(d) -100 <= grid[i][j] <= 100

例1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

例2:
Input: grid = [[3,2],[1,0]]
Output: 0

例3:
Input: grid = [[1,-1],[-1,-1]]
Output: 3

例4:
Input: grid = [[-1]]
Output: 1
*/
#include "leetcode.h"

namespace q1351{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<vector<int>> grid {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
        CHECK_RET(8 == slt.countNegatives(grid));
    }

    {
        vector<vector<int>> grid {{3,2},{1,0}};
        CHECK_RET(0 == slt.countNegatives(grid));
    }

    {
        vector<vector<int>> grid {{1,-1},{-1,-1}};
        CHECK_RET(3 == slt.countNegatives(grid));
    }

    {
        vector<vector<int>> grid {{-1}};
        CHECK_RET(1 == slt.countNegatives(grid));
    }

    // succ
    return true;
}

class Solution {
public:
    // 2020-03-06
    // Runtime: 20 ms, faster than 59.23%
    // Memory Usage: 9.4 MB, less than 100.00%
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        for (auto & r : grid) {
            for (auto & v : r) {
                if (v < 0) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
TEST(Q1351, Solution) {EXPECT_TRUE(q1351::run_testcases<q1351::Solution>());}

class Solution02 {
public:
    // Runtime: 16 ms, faster than 93.57%
    // Memory Usage: 9.4 MB, less than 100.00%
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size() - 1, n = grid[0].size() - 1;
        int ret = 0, end = 0, c = 0;
        for (; m >= 0; --m) {
            for (c = n; c >= end; --c) {
                if (grid[m][c] < 0) {
                    ++ret;
                } else {
                    end = c + 1;
                    break;
                }
            }
            if (end > n) {
                break;
            }
        }
        return ret;
    }
};
TEST(Q1351, Solution02) {EXPECT_TRUE(q1351::run_testcases<q1351::Solution02>());}

class Solution03 {
public:
    // Runtime: 16 ms, faster than 93.46%
    // Memory Usage: 9.4 MB, less than 100.00%
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int ret = 0, low = 0, high = n - 1, mid = 0;
        for (auto & row : grid) {
            low = 0;
            high = n - 1;
            // all elements are non-negative
            if (row[high] >= 0) {
                continue;
            } 
            // all elements are negative
            if (row[low] < 0) {
                ret += n;
                continue;
            }
            // binary search
            while (low < high) {
                mid = (low + high) / 2;
                if (row[mid] < 0) {
                    high = mid;
                } else {
                    low = mid+1;
                }
            }
            // cout << low << "," << high<< endl;
            ret += n - low;
        }
        return ret;
    }
};
TEST(Q1351, Solution03) {EXPECT_TRUE(q1351::run_testcases<q1351::Solution03>());}
};