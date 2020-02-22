/*
#面试刷题# 第0052期
#Leetcode# Q1292 总和小于或等于阈值的正方形的最大边长
难度：中
给定一个m x n矩阵垫和一个整数阈值。返回总和小于或等于阈值的正方形的最大边长；
如果没有这样的正方形，则返回0。
约束条件：
(a) 1 <= m, n <= 300
(b) m == mat.length
(c) n == mat[i].length
(d) 0 <= mat[i][j] <= 10000
(e) 0 <= threshold <= 10^5

例1:
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

例2:
Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0

例3:
Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
Output: 3

例4:
Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
Output: 2
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int compute_integral(vector<vector<int>>& mat, vector<vector<int>>& integral) {
        int m = mat.size(), n = mat[0].size();
        integral[0][0] = mat[0][0];
        int i = 1, j = 1, max_val = 0;
        for (;i < m; ++i) {
            integral[i][0] = integral[i-1][0] + mat[i][0];
            if (max_val < mat[i][0]) {
                max_val = mat[i][0];
            }
        }
        for (;j < n; ++j) {
            integral[0][j] = integral[0][j-1] + mat[0][j];
            if (max_val < mat[0][j]) {
                max_val = mat[0][j];
            }
        }
        for (i = 1; i < m; ++i) {
            for (j = 1; j < n; ++j) {
                integral[i][j] = mat[i][j] + \
                    integral[i-1][j] + integral[i][j-1] - integral[i-1][j-1];
                if (max_val < mat[i][j]) {
                    max_val = mat[i][j];
                }
            }
        }
        return max_val;
    }
    
    int get_value_from_integral(
        vector<vector<int>>& integral, int i, int j, int row, int col) {
        int val = 0;
        if (0 == i && 0 == j) {
            val = integral[row][col];
        } else if (0 == i) {
            val = integral[row][col] - integral[row][j-1];
        } else if (0 == j) {
            val = integral[row][col] - integral[i-1][col];
        } else {
            val = integral[row][col] - integral[i-1][col] \
                      - integral[row][j-1] + integral[i-1][j-1];
        }
        return val;
    }
    
    bool is_satisfied(
        vector<vector<int>>& integral, int max_row, int max_col, int side, int threshold) {
        int row = 0, col = 0;
        for (int i = 0; i <= max_row; ++i) {
            for (int j = 0; j <= max_col; ++j) {
                row = i + side - 1;
                col = j + side - 1;
                // update return value
                if (get_value_from_integral(integral, i, j, row, col) <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // Runtime: 296 ms, faster than 22.37% 
    // Memory Usage: 19.8 MB, less than 100.00% 
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        // build integral matrix
        vector<vector<int>> integral(m, vector<int>(n, 0));
        int max_val = compute_integral(mat, integral);
        if (max_val > threshold) {
            return 0;
        }
        // count max slide length
        int side = 2, max_side = min(m,n), ret = 1;
        int max_row = 0, max_col = 0;
        for (;side <= max_side; ++side) {
            // compute 
            max_row = m - side;
            max_col = n - side;
            if (is_satisfied(integral, max_row, max_col, side, threshold) && ret < side) {
                ret = side;
            }
        }
        return ret;
    }
};
