/*
#面试刷题# 第0054期
#Leetcode# Q1283 查找给定阈值的最小除数
难度：中
给定一个整数nums数组和一个整数阈值，我们将选择一个正整数除数，
然后将所有数组除以该整数并将除法的结果求和。
找到最小除数，使上述结果小于或等于阈值。
每个除法结果均舍入为大于或等于该元素的最接近整数。 （例如：7/3 = 3和10/2 = 5）。
保证会有答案。
约束条件：
(a) 1 <= nums.length <= 5 * 10^4
(b) 1 <= nums[i] <= 10^6
(c) nums.length <= threshold <= 10^6

例1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

例2:
Input: nums = [2,3,5,7,11], threshold = 11
Output: 3

例3:
Input: nums = [19], threshold = 5
Output: 4
*/
#include "leetcode.h"
namespace q1283{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    int is_sum_greater(vector<int>& nums, int div, int threshold) {
        int sum = 0, digit = 0;
        for (auto & n : nums) {
            digit = n / div;
            if (n % div != 0) {
                ++digit;
            }
            sum += digit;
            if (sum > threshold) {
                return true;
            }
        }
        return false;
    }
    
    // Runtime: 48 ms, faster than 79.62%
    // Memory Usage: 11.6 MB, less than 100.00%
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1000000, mid = 0;
        while(low < high) {
            mid = (low + high) / 2;
            if (is_sum_greater(nums, mid, threshold)) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
};