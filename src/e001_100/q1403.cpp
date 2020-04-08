/*
#面试刷题# 第0087期
#Leetcode# Q14003 非递增顺序的最小子序列
难度：低
给定数组num，请获取其元素总数严格大于该子序列中未包括元素的总数的数组子序列。
如果存在多个解决方案，则以最小的大小返回子序列，如果仍然存在多个解决方案，
则以其所有元素的最大总和返回子序列。 可以通过从数组中删除一些（可能为零）元素来获得数组的子序列。
注意，具有给定约束的解决方案保证是唯一的。 还返回以非递增顺序排序的答案。
约束条件：
1 <= nums.length <= 500
1 <= nums[i] <= 100

示例1:
Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 

示例2:
Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.  

示例3:
Input: nums = [6]
Output: [6]
*/
#include "leetcode.h"

namespace q1403{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

// 该方案适用于要求连续子序列的情况，因此在这里不适用。
class Solution_exp {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int low=0, high=0,c_sum=0;
        int ret_low=0, ret_high=1, ret_sum=0;
        while(high <= n) {
            // cout << low << "," << high << "," << c_sum << endl;
            // find a valid one
            if (c_sum * 2 > sum) {
                if (ret_sum == 0 || high - low < ret_high - ret_low) {
                    // record
                    ret_low = low, ret_high = high, ret_sum = c_sum;
                } else if (high - low == ret_high - ret_low) {
                    if (c_sum > ret_sum) {
                        // record
                        ret_low = low, ret_high = high, ret_sum = c_sum;
                    }
                }
                // move low index
                c_sum -= nums[low];
                ++low;
            } else {
                // move high index
                if (high < n) {
                    c_sum += nums[high];
                }
                ++high;
            }
        }
        // get result
        vector<int> ret;
        ret.reserve(ret_high - ret_low);
        for (int i = ret_low; i < ret_high; ++i) {
            ret.push_back(nums[i]);
        }
        sort(ret.rbegin(), ret.rend());
        return ret;
    }
};

// Runtime: 20 ms, faster than 33.33%
// Memory Usage: 10.7 MB, less than 100.00%
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // sort by descending order
        sort(nums.rbegin(), nums.rend());
        // accept the largest someones
        vector<int> ret;
        int c_sum = 0;
        for (auto & n : nums) {
            ret.push_back(n);
            c_sum += n;
            if (c_sum * 2 > sum) {
                break;
            }
        }
        return ret;
    }
};

};
