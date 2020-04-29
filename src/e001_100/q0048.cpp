/*
#面试刷题# 第0040期
#Leetcode# Q0048 旋转图像
难度：中(收费)
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

例1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

例2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
#include "leetcode.h"

namespace q0048{

template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
        vector<vector<int>> ret{{7,4,1},{8,5,2},{9,6,3}};
        slt.rotate(matrix);
        CHECK_RET(comp_matrix(matrix, ret));
    }

    // example 02
    {
        vector<vector<int>> matrix{{5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
        vector<vector<int>> ret{{15,13, 2, 5},{14, 3, 4, 1},{12, 6, 8, 9},{16, 7,10,11}};
        slt.rotate(matrix);
        CHECK_RET(comp_matrix(matrix, ret));
    }

    return true;
}

class Solution {
public:
    // 执行用时 :4 ms, 在所有 C++ 提交中击败了84.58% 
    // 内存消耗 :9.2 MB, 在所有 C++ 提交中击败了5.22%
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n / 2, size = n, tmp=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<size-1; ++j) {
                // backup r = 0, c = j
                tmp = matrix[i][i + j];
                // r = size - 1 - j, c = 0;
                matrix[i][i+j] = matrix[i + size-1-j][i];
                // r = size - 1, c = size - 1 - j
                matrix[i + size-1-j][i] = matrix[i + size - 1][i + size - 1 -j];
                // r = j, c = size - 1
                matrix[i + size - 1][i + size - 1 -j] = matrix[i + j][i + size - 1];
                // r = 0, c = j;
                matrix[i + j][i + size - 1] = tmp;
            }
            size -= 2;
        }
    }
};
TEST(Q0048, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

};