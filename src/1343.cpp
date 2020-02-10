/*
#面试刷题# 第0026期
#Leetcode# Q1343 大小为K且平均值大于或等于阈值的子数组的数量
难度：中
给定一个整数数组arr和两个整数k和threshold。
返回大小为k且平均值大于或等于threshold的子数组的数量。
约束条件：
(a) 1 <= arr.length <= 10^5
(b) 1 <= arr[i] <= 10^4
(c) 1 <= k <= arr.length
(d) 0 <= threshold <= 10^4

例1:
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

例2:
Input: arr = [1,1,1,1,1], k = 1, threshold = 0
Output: 5

例3：
Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.

例4:
Input: arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
Output: 1

例5:
Input: arr = [4,4,4,4], k = 4, threshold = 1
Output: 1
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Runtime: 120 ms, faster than 70.69%
    // Memory Usage: 16.3 MB, less than 100.00%
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int len = arr.size();
        int sum = 0, count=0;
        int thresh = threshold * k;
        for (int i=0; i<len; ++i) {
            sum += arr[i];
            // keep k-size sub-array
            if (i>=k) {
                sum -= arr[i-k];
            }
            // counter
            if ((i>=k-1) && (sum>=thresh)) {
                ++count;
            }
        }
        return count;
    }
};
