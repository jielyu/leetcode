/*
#面试刷题# 第0044期
#Leetcode# Q1306 跳跃游戏III
难度：中
给定一个非负整数arr数组，您最初位于该数组的起始索引处。
当您位于索引i处时，可以跳转到i + arr [i]或i-arr [i]，
检查是否可以到达任何值为0的索引。
请注意，您无法随时跳出阵列。
约束条件：
(a) 1 <= arr.length <= 5 * 10^4
(b) 0 <= arr[i] < arr.length
(c) 0 <= start < arr.length

例1:
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

例2:
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3

例3:
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool isReach(vector<int> & arr, int start, vector<bool> & used) {
        if (0 == arr[start]) {
            return true;
        }
        // mark current index
        used[start] = true;
        bool ret = false;
        int left = start - arr[start], right = start + arr[start];
        // explore the left one
        if (left >= 0 && !used[left]) {
            ret = ret || isReach(arr, left, used);
        }
        // explore the right one
        if (right < arr.size() && !used[right]) {
            ret = ret || isReach(arr, right, used);
        }
        return ret;
    }
    
    // Runtime: 48 ms, faster than 93.65%
    // Memory Usage: 12.5 MB, less than 100.00%
    bool canReach(vector<int>& arr, int start) {
        vector<bool> used(arr.size(), false);
        return isReach(arr, start, used);
    }
};