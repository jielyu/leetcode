/*
#面试刷题# 第0037期
#Leetcode# Q1314 矩阵块总和
难度：中
给定一个m * n矩阵mat和整数K，返回矩阵answer，其中每个answer[i] [j]是i-K <= r <= i + K
的所有元素mat [r] [c]的和。 j-K <= c <= j + K，并且（r，c）是矩阵中的有效位置。
约束条件：
(a) m == mat.length
(b) n == mat[i].length
(c) 1 <= m, n, K <= 100
(d) 1 <= mat[i][j] <= 100

例1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

例2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
*/
#include "leetcode.h"

namespace q1314{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
        int K = 1;
        vector<vector<int>> ret{{12,21,16},{27,45,33},{24,39,28}};
        if (!comp_matrix(ret, slt.matrixBlockSum(mat, K))) {return false;}
    }

    {
        vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
        int K = 2;
        vector<vector<int>> ret{{45,45,45},{45,45,45},{45,45,45}};
        if (!comp_matrix(ret, slt.matrixBlockSum(mat, K))) {return false;}
    }

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 672 ms, faster than 16.24%
    // Memory Usage: 11.1 MB, less than 100.00% 
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        int r_min = 0, r_max = 0, c_min = 0, c_max = 0;
        int i = 0, j = 0, ii = 0, jj = 0;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                r_min = i - K >= 0 ? i-K : 0;
                r_max = i + K < m ? i+K : m-1;
                c_min = j - K >= 0 ? j-K : 0;
                c_max = j + K < n ? j+K : n-1;
                for (ii=r_min; ii<=r_max; ++ii) {
                    for (jj=c_min; jj<=c_max; ++jj) {
                        ret[i][j] += mat[ii][jj];
                    }
                }
            }
        }
        return ret;
    }
};
TEST(Q1314, Solution) {EXPECT_EQ(q1314::run_testcases<q1314::Solution>(), true);}

class Solution02 {
public:
    // Runtime: 24 ms, faster than 96.37%
    // Memory Usage: 11.5 MB, less than 100.00%
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> calc(m, vector<int>(n, 0));
        calc[0][0] = mat[0][0];
        int i = 0, j = 0;
        int r_min = 0, r_max = 0, c_min = 0, c_max = 0;
        // create integral matrix
        for (i = 1; i < m; ++i) {
            calc[i][0] = calc[i-1][0] + mat[i][0]; 
        }
        for (j = 1; j < n; ++j) {
            calc[0][j] = calc[0][j-1] + mat[0][j];
        }
        for (i = 1; i < m; ++i) {
            for (j = 1; j < n; ++j) {
                calc[i][j] = mat[i][j] + \
                    calc[i-1][j] + calc[i][j-1] - calc[i-1][j-1];
            }            
        }
        // compute results
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                r_min = i - K >= 0 ? i-K : 0;
                r_max = i + K < m ? i+K : m-1;
                c_min = j - K >= 0 ? j-K : 0;
                c_max = j + K < n ? j+K : n-1;
                ret[i][j] = calc[r_max][c_max];
                if (r_min > 0) {
                    ret[i][j] -= calc[r_min-1][c_max];
                }
                if (c_min > 0) {
                    ret[i][j] -= calc[r_max][c_min-1];
                } 
                if (r_min > 0 && c_min > 0) {
                    ret[i][j] += calc[r_min-1][c_min-1];
                }
            }
        }
        return ret;
    }
};
TEST(Q1314, Solution02) {EXPECT_EQ(q1314::run_testcases<q1314::Solution02>(), true);}
};
