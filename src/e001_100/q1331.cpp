/*
#面试刷题# 第0021期
#Leetcode# Q1331 数组的秩变换
给定一个整数数组arr，将每个元素替换为其等级。
等级表示元素的大小。等级具有以下规则：
（1）等级是从1开始的整数。
（2）元素越大，等级越高。如果两个元素相等，则它们的等级必须相同。
（3）等级应尽可能小。
约束条件：
(a) 0 <= arr.length <= 10^5
(b)-10^9 <= arr[i] <= 10^9

例1:
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

例2:
Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.

例3:
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
*/
#include "leetcode.h"

namespace q1331{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 240 ms, faster than 70.81%
    // Memory Usage: 32.5 MB, less than 100.00%
    vector<int> arrayRankTransform(vector<int>& arr) {
        // get unique elements
        set<int> uniq;
        for (auto & v : arr) {
            uniq.insert(v);
        }
        // build dict
        unordered_map<int, int> dict;
        int value = 1;
        for (auto & v : uniq) {
            dict[v] = value;
            ++value;
        }
        // get results;
        vector<int> ret;
        for (auto & v : arr) {
            ret.push_back(dict[v]);
        }
        return ret;
    }
};
};