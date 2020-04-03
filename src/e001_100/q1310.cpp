/*
#面试刷题# 第0042期
#Leetcode# Q1310 子数组的XOR查询
难度：中
给定正整数的数组arr和其中query [i] = [Li，Ri]的数组查询，对于每个查询i，
计算元素从Li到Ri的XOR（即arr [Li] xor arr [Li + 1] ] xor ... xor arr [Ri]）。
返回一个包含给定查询结果的数组。
约束条件：
(a) 1 <= arr.length <= 3 * 10^4
(b) 1 <= arr[i] <= 10^9
(c) 1 <= queries.length <= 3 * 10^4
(d) queries[i].length == 2
(e) 0 <= queries[i][0] <= queries[i][1] < arr.length

例1:
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8

例2:
Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Runtime: 136 ms, faster than 56.90%
    // Memory Usage: 25.8 MB, less than 100.00%
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int len = arr.size();
        vector<int> ret, xor_buff;
        ret.reserve(queries.size());
        xor_buff.reserve(len);
        // compute xor buffer
        xor_buff.push_back(arr[0]);
        for (int i = 1; i < len; ++i) {
            xor_buff.push_back(xor_buff[i-1]^arr[i]);
        }
        // get results, take advantage of one of xor principles
        for (auto & q : queries) {
            if (0 == q[0]) {
                ret.push_back(xor_buff[q[1]]);
            } else {
                ret.push_back(xor_buff[q[0]-1]^xor_buff[q[1]]);
            }
        }
        return ret;
    }
    
    // Time Limit Exceeded
    vector<int> xorQueries_2(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ret;
        ret.reserve(queries.size());
        int tmp = 0, i = 0;
        for (auto & q : queries) {
            tmp = arr[q[0]];
            for (i = q[0] + 1; i <= q[1]; ++i) {
                tmp ^= arr[i];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
