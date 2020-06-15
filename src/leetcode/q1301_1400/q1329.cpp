/*
#面试刷题# 第0022期
#Leetcode# Q1329 对角矩阵排序
难度：中
给定一个m * n整数矩阵，按从左上角到右下角的升序对角对其进行排序，然后返回排序后的数组。
约束条件：
(a) m == mat.length
(b) n == mat[i].length
(c) 1 <= m, n <= 100
(d) 1 <= mat[i][j] <= 100

例1:
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
*/
#include "leetcode.h"

namespace q1329{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<vector<int>> mat{{3,3,1,1},{2,2,1,2},{1,1,1,2}},
                            ret{{1,1,1,1},{1,2,2,2},{1,2,3,3}};
        if (!comp_matrix(ret, slt.diagonalSort(mat))) {return false;}

    }

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 28 ms, faster than 88.50%
    // Memory Usage: 10.6 MB, less than 100.00%
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> buff;  // avoid creating object repeatedly
        int r = 0, c = 0;
        // sort right-up
        for (int i=0; i<n; ++i) {
            buff.clear();
            r = 0, c = i;
            while(r < m && c < n) {
                buff.push_back(mat[r++][c++]);
            }
            // sort diag
            sort(buff.begin(), buff.end());
            // fill into mat
            r = 0, c = i;
            for (auto & v : buff) {
                mat[r++][c++] = v;
            }
        }
        // sort left-bottom
        for (int i=1; i<m; ++i) {
            buff.clear();
            r = i, c = 0;
            while (r < m && c < n) {
                buff.push_back(mat[r++][c++]);
            }
            // sort diag
            sort(buff.begin(), buff.end());
            // fill into mat
            r = i, c = 0;
            for (auto & v : buff) {
                mat[r++][c++] = v;
            }
        }
        return mat;
    }
};
TEST(Q1329, Solution) {EXPECT_EQ(q1329::run_testcases<q1329::Solution>(), true);}
};
