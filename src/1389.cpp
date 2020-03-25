/*
#Leetcode# Q1389 按给定顺序创建目标数组
难度：低
给定两个整数数组nums和index。 您的任务是根据以下规则创建目标数组：
(1) 最初目标数组为空。
(2) 从左到右读取nums [i]和index [i]，在目标数组中的索引index[i]处插入nums[i]值。
(3) 重复上一步，直到没有要读取的元素为nums和index。
返回目标数组。
保证插入操作将是有效的。
约束条件：
(a) 1 <= nums.length, index.length <= 100
(b) nums.length == index.length
(c) 0 <= nums[i] <= 100
(d) 0 <= index[i] <= i

例1:
Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]

例2:
Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]

例3:
Input: nums = [1], index = [0]
Output: [1]
*/

/*
提示：数组元素的插入操作就是插入点右侧元素后移
*/


// Runtime: 4 ms, faster than 66.38%
// Memory Usage: 8.6 MB, less than 100.00%
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            // shift elements to the right
            for (int j = n - 2; j >= index[i]; --j) {
                ret[j+1] = ret[j];
            }
            // fill current element
            ret[index[i]] = nums[i];
        }
        return ret;
    }
};
