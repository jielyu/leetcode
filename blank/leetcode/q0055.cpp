
/*
#LeetCode# Q0055 跳跃游戏
难度：中

给定一个非负整数的数组，你最初被定位在数组的第一个索引处。

数组中的每个元素代表你在该位置的最大跳跃长度。

判断你是否能够到达最后一个索引。
Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/
#include "leetcode.h"

namespace q0055
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 32 ms, faster than 13.19%
// Memory Usage: 13.1 MB, less than 11.33%
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 记录到达的最大索引
        int max_idx = 0, len = nums.size();
        // 只有一个元素直接返回
        if (len <= 1) {return true;}
        for (int i = 0; i < len; ++i) {
            // 遇到0点，最大可达还没到达终点，则失败
            if (0 == nums[i] && max_idx <= i) {return false;}
            // 如果最大可达位置超过了长度，则成功
            if (i + nums[i] >= len - 1) {return true;}
            // 记录最大可到位置
            if (max_idx < i + nums[i]) {
                max_idx = i + nums[i];
            }
            //cout << max_idx << endl;
        }
        return true;
    }
};


// untime: 24 ms, faster than 20.49%
// Memory Usage: 13.1 MB, less than 8.69%
class Solution02 {
public:
    bool canJump(vector<int>& nums) {
        // 记录到达的最大索引
        int len = nums.size(), i = 0;
        // 只有一个元素直接返回
        if (len <= 1) {return true;}
        while (i < len) {
            // 到达一个吸收节点，则失败
            if (nums[i] == 0 && i < len) {return false;}
            if (i + nums[i] >= len - 1) {return true;}
            // 搜索i到i+nums[i] 之间的所有位置，选择最好的位置
            int max_pos = i + nums[i], best_idx = i + 1, max_idx = 0;
            for (int k = i + 1; k <= max_pos && k < len; ++k) {
                // 最好的节点也就是跳得最远的节点
                if (k + nums[k] > max_idx) {
                    // 记录最远的位置和当前位置
                    max_idx = k + nums[k];
                    best_idx = k;
                }
            }
            i = best_idx;
            //cout << i << "," << max_idx << endl;
        }
        return true;
    }
};

} // namespace q0055
