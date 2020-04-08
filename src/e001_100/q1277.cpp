/*
#面试刷题# 第0005期
#Leetcode# Q1277 计数全1子矩阵
给定一个m * n由1和0组成的矩阵，返回有多少个正方形子矩阵全部为1。
约束条件：
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
例1:
Input: matrix =
[
[0,1,1,1],
[1,1,1,1],
[0,1,1,1]
]
Output: 15
例2:
Input: matrix =
[
[1,0,1],
[1,1,0],
[1,1,0]
]
Output: 7
*/
#include "leetcode.h"
namespace q1277{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}


class Solution {
public:
    bool is_ones(vector<vector<int>>& matrix, int i, int j, int k) {
        int max_row = i + k;
        int max_col = j + k;
        for (int r=i; r<max_row; ++r) {
            for (int c=j; c<max_col; ++c) {
                if(0 == matrix[r][c]) {
                    return false;
                }
            }
        }
        return true;
    }

    // 76ms, faster than 30.29%, not good
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int w = m < n ? m : n;
        
        int sum = 0, last_sum = 0;
        for (int k=1; k<=w; ++k) {
            if (1 == k){ // to speed up
                for (int i=0; i<=m-k; ++i) {
                    for (int j=0; j<=n-k; ++j) {
                        sum += matrix[i][j];
                    }
                }
            } else {
                 for (int i=0; i<=m-k; ++i) {
                    for (int j=0; j<=n-k; ++j) {
                        if (matrix[i][j]) {
                            sum += int(is_ones(matrix, i, j, k));
                        }
                    }
                }
            }
            // finish in advance
            if (sum > last_sum) {
                last_sum = sum;
            } else {
                break;
            }
            
        }
        return sum;
    }
};

};