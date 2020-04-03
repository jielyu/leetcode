/*
#面试刷题# 第0038期
#Leetcode# Q1313 解压缩行程编码列表
难度：低
我们得到了一个整数列表，代表用游程长度编码压缩的列表。
考虑每对相邻的元素对[a，b] = [nums [2 * i]，nums [2 * i + 1]]（其中i> = 0）。
对于每个这样的对，在解压缩列表中都有一个值为b的元素。
返回解压缩后的列表。
约束条件：
(a) 2 <= nums.length <= 100
(b) nums.length % 2 == 0
(c) 1 <= nums[i] <= 100

例1:
Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4,4] is [2,4,4,4].
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Runtime: 36 ms, faster than 99.93%
    // Memory Usage: 10.1 MB, less than 100.00%
    vector<int> decompressRLElist(vector<int>& nums) {
        int len = nums.size() / 2;
        int max_len = 0;
        for (int i = 0; i < len; ++i) {
            max_len += nums[2*i];
        }
        vector<int> ret(max_len, 0);
        int idx = 0;
        for (int i = 0; i < len; ++i) {
            auto start_it = ret.begin() + idx;
            auto end_it = start_it + nums[2*i];
            fill(start_it, end_it, nums[2*i+1]);
            idx += nums[2*i];
        }
        return ret;
    }
    
    // Runtime: 44 ms, faster than 90.58%
    // Memory Usage: 10.6 MB, less than 100.00% 
    vector<int> decompressRLElist_2(vector<int>& nums) {
        int len = nums.size() / 2;
        vector<int> ret;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < nums[2*i]; ++j) {
                ret.push_back(nums[2*i+1]);
            }
        }
        return ret;
    }
};