/*
#面试刷题# 第0049期
#Leetcode# Q1299 用右侧的最大元素替换元素
难度：低
给定一个数组arr，用该数组右边的元素中最大的元素替换该数组中的每个元素，
并将最后一个元素替换为-1。这样做之后，返回数组。
约束条件：
(a) 1 <= arr.length <= 10^4
(b) 1 <= arr[i] <= 10^5

例1:
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
*/
#include "leetcode.h"

namespace q1299{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 460 ms, faster than 12.11%
    // Memory Usage: 10.6 MB, less than 100.00%
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size(), r_max = 0;
        for (int i = 0; i < len; ++i) {
            r_max = 0;
            for (int j = i+1; j < len; ++j) {
                if (arr[j] > r_max) {
                    r_max = arr[j];
                }
            }
            arr[i] = r_max;
        }
        arr[len-1] = -1;
        return arr;
    }
};

class Solution02 {
public:
    // Runtime: 52 ms, faster than 78.82% 
    // Memory Usage: 10.6 MB, less than 100.00%
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        vector<int> max_vec(len, 0);
        int r_max = -1;
        for (int i = len-1; i >= 0; --i) {
            max_vec[i] = r_max;
            if (arr[i] > r_max) {
                r_max = arr[i];
            }
        }
        return max_vec;
    }
};

class Solution03 {
public:
    // Runtime: 48 ms, faster than 94.53%
    // Memory Usage: 10.7 MB, less than 100.00%
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        int r_max = -1, tmp = 0;
        for (int i = len-1; i >= 0; --i) {
            tmp = arr[i];
            arr[i] = r_max;
            if (tmp > r_max) {
                r_max = tmp;
            }
        }
        return arr;
    }
};

};
