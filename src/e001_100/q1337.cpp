/*
#面试刷题# 第0015期
#Leetcode# Q1337 矩阵中K个最弱的行
难度：低
给定一个m * n矩阵矩阵，矩阵矩阵中的1（代表士兵）和0（代表平民），返回矩阵中k个最弱行的索引，从最弱到最强。
如果第i行的士兵人数少于第j行的士兵人数，或者他们的士兵人数相同但i小于j，则第i行比第j行弱。士兵总是排成一列，也就是说，士兵总是先出现然后是零。
约束条件：
(a) m == mat.length
(b) n == mat[i].length
(c) 2 <= n, m <= 100
(d) 1 <= k <= m
(e) matrix[i][j]是 0 或者 1.

例1:
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]

例2:
Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
*/
#include "leetcode.h"

namespace q1337{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Comp{
private:
    vector<int> * _buff;
public:
    Comp(vector<int> * buff) {
        this->_buff = buff;
    }
    
    bool operator()(int i, int j) {
        if ((*_buff)[i] == (*_buff)[j]) {
            return i < j;
        }
        return (*_buff)[i] < (*_buff)[j];
    }
};

class Solution {
public:
    // Runtime: 20 ms, faster than 16.74%
    // Memory Usage: 10.4 MB, less than 100.00%
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // cosntruct row and its index vector
        set<pair<int, int>> buff;
        auto row_size = mat.size();
        for (int i=0; i < row_size; ++i) {
            auto t = accumulate(mat[i].begin(), mat[i].end(), 0);
            buff.insert({t, i});
        }
        // return the first k indexes
        vector<int> ret;
        for (auto iter = buff.begin(); k > 0; ++iter, --k) {
            ret.push_back(iter->second);
        }
        return ret;
    }
};

class Solution02 {
public:
    // Runtime: 16 ms, faster than 33.32%
    // Memory Usage: 10.3 MB, less than 100.00% 
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // cosntruct row and its index vector
        vector<int> row, row_idx;
        int cnt = 0;
        for (auto & r : mat) {
            row.push_back(accumulate(r.begin(), r.end(), 0));
            row_idx.push_back(cnt);
            ++cnt;
        }
        // sort 
        Comp comp(&row);
        sort(row_idx.begin(), row_idx.end(), comp);
        // return the first k indexes
        vector<int> ret;
        int row_size = row.size();
        for (int i=0; i < k && i < row_size; ++i) {
            ret.push_back(row_idx[i]);
        }
        return ret;
    }
};

};

