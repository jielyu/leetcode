/*
#面试刷题# 第0011期
#Leetcode# Q1287 有序数组中出现次数超过25%的元素
难度：低
给定一个非降序数组，其中必定有一个数字出现的次数超过总元素的25%，请返回该数字。
约束条件：
(a) 1 <= arr.length <= 10^4
(b) 0 <= arr[i] <= 10^5

例1:
Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
*/
#include "leetcode.h"
namespace q1287{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // 20 ms, faster than 46.32% 
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        int current = -1, cnt = 0, thresh = len/4 + 1;
        for (auto & v : arr) {
            // add up if meet the same one
            if (v == current) {
                ++cnt;
            } else {
                // check the last number
                if (cnt >= thresh) {
                    return current;
                }
                current = v;
                cnt = 1; 
            }
        }
        // check the last number
        if (cnt >= thresh) {
            return current;
        }
        return 0;
    }
};
};