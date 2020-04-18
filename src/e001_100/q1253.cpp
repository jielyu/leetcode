/*
#面试刷题# 第0099期
#Leetcode# Q1253 重建2行二值矩阵
难度：中
给定n列2行的矩阵的以下详细信息：
(1)矩阵是二值矩阵，这意味着矩阵中的每个元素可以为0或1。
(2)第0（上）行的元素总和为 upper。
(3)第1个（较低）行的元素总和给出为 lower。
(4)第i列（索引为0）中的元素之和为colsum [i]，其中colsum作为长度为n的整数数组给出。
您的任务是用上，下和求和重建矩阵。将其作为二维整数数组返回。
如果有多个有效的解决方案，则将接受其中任何一个。
如果不存在有效的解决方案，则返回一个空的二维数组。
约束条件：
1 <= colsum.length <= 10^5
0 <= upper, lower <= colsum.length
0 <= colsum[i] <= 2

示例1:
Input: upper = 2, lower = 1, colsum = [1,1,1]
Output: [[1,1,0],[0,0,1]]
Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.

示例2:
Input: upper = 2, lower = 3, colsum = [2,2,1,1]
Output: []

示例3:
Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
*/
#include "leetcode.h"

namespace q1253 {

// compare the result given by solution and the groundtruth
bool comp_mat(const vector<vector<int>> & v1, const vector<vector<int>> & v2){
    if ((v1.size() == 0) && (v2.size() == 0)) {return true;}
    if (v1.size() != v2.size() || v1.size() != 2) {return false;}
    if (v1[0].size() != v2[0].size()) {return false;}
    int u1 = 0, u2 = 0, l1 = 0, l2 = 0;
    for (int i = 0; i < v1[0].size(); ++i) {
        u1 += v1[0][i]; l1 += v1[1][i];
        u2 += v2[0][i]; l2 += v2[1][i];
        if (v1[0][i]+v1[1][i] != v2[0][i]+v2[1][i]) {return false;}
    }
    if (u1 != u2 || l1 != l2) {return false;}
    return true;
}

template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        int upper = 2, lower = 1;
        vector<int> colsum{1,1,1};
        vector<vector<int>> ret{{1,1,0},{0,0,1}};
        if (!q1253::comp_mat(slt.reconstructMatrix(upper, lower, colsum), ret)) {return false;}
    }
    // example 02
    {
        int upper = 2, lower = 3;
        vector<int> colsum{2,2,1,1};
        vector<vector<int>> ret;
        if (!q1253::comp_mat(slt.reconstructMatrix(upper, lower, colsum), ret)) {return false;}
    }
    // example 03
    {
        int upper = 5, lower = 5;
        vector<int> colsum{2,1,2,0,1,0,1,2,0,1};
        vector<vector<int>> ret{{1,1,1,0,1,0,0,1,0,0},{1,0,1,0,0,0,1,1,0,1}};
        if (!q1253::comp_mat(slt.reconstructMatrix(upper, lower, colsum), ret)) {return false;}
    }

    return true;
}

// Runtime: 400 ms, faster than 5.36%
// Memory Usage: 23.2 MB, less than 100.00%
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ret(2, vector<int>(n, 1));
        vector<int> idx_ones;
        idx_ones.reserve(n);
        // solve certain situation for all zeros and all ones
        vector<int> sum_row(2, n);
        for (int i = 0; i < n; ++i) {
            if (0 == colsum[i]) {
                ret[0][i] = 0;
                ret[1][i] = 0;
                --sum_row[0];
                --sum_row[1];
            } else if (1 == colsum[i]) {
                idx_ones.push_back(i);
            }
        }
        // record remainder ones
        sum_row[0] -= upper;
        sum_row[1] -= lower;
        // remove one from row of greater remainder
        for (auto & i : idx_ones) {
            auto idx = (int)(sum_row[1] > sum_row[0]);
            --ret[idx][i];
            --sum_row[idx];
        }
        if (0 == sum_row[0] && 0 == sum_row[1]) {
            return ret;
        }
        return {};
    }
};
TEST(Q1253, Solution) {EXPECT_EQ(q1253::run_testcases<q1253::Solution>(), true);}

// Runtime: 316 ms, faster than 39.29%
// Memory Usage: 22.4 MB, less than 100.00%
class Solution02 {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size(), idx = 0;
        vector<vector<int>> ret(2, vector<int>(n, 1));
        // record remainder ones
        vector<int> sum_row(2, n);
        sum_row[0] -= upper;
        sum_row[1] -= lower;
        if (sum_row[0] < 0 || sum_row[1] < 0) {
            return {};
        }
        // remove ones 
        for (int i = 0; i < n; ++i) {
            if (2 == colsum[i]){
                continue;
            } else if (0 == colsum[i]) {
                ret[0][i] = 0;
                ret[1][i] = 0;
                --sum_row[0];
                --sum_row[1];
            } else {
                idx = (int)(sum_row[1] > sum_row[0]);
                --ret[idx][i];
                --sum_row[idx];
            }
        }
        // check sum of upper row and sum of lower row
        if (0 == sum_row[0] && 0 == sum_row[1]) {
            return ret;
        }
        return {};
    }
};
TEST(Q1253, Solution02) {EXPECT_EQ(q1253::run_testcases<q1253::Solution02>(), true);}

// Runtime: 432 ms, faster than 5.36%
// Memory Usage: 22.4 MB, less than 100.00%
class Solution03 {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size(), idx = 0;
        vector<vector<int>> ret(2, vector<int>(n, 0));
        // record remainder ones
        vector<int> sum_row(2, 0);
        sum_row[0] -= upper;
        sum_row[1] -= lower;
        // remove ones 
        for (int i = 0; i < n; ++i) {
            if (2 == colsum[i]){
                ret[0][i] = 1;
                ret[1][i] = 1;
                ++sum_row[0];
                ++sum_row[1];
            } else if (0 == colsum[i]) {
                ret[0][i] = 0;
                ret[1][i] = 0;
            } else {
                idx = (int)(sum_row[1] < sum_row[0]);
                ++ret[idx][i];
                ++sum_row[idx];
            }
        }
        // check sum of upper row and sum of lower row
        if (0 == sum_row[0] && 0 == sum_row[1]) {
            return ret;
        }
        return {};
    }
};
TEST(Q1253, Solution03) {EXPECT_EQ(q1253::run_testcases<q1253::Solution03>(), true);}
};