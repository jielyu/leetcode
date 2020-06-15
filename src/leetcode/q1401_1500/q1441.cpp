/*
#面试刷题# 第118期
#Leetcode# Q1441 使用堆栈操作构建一个阵列
难度：低
给定一个数组目标和一个整数n，在每次迭代中，从list = {1,2,3...,n}中读取一个数字。
使用下面的操作来建立目标数组:
(1) Push。从开始的列表中读取一个新元素，并将其推送到数组中。
(2) Pop：删除数组中的最后一个元素。
(3) 如果目标数组已经构建好了，则停止读取更多的元素。
可以保证目标数组是严格增加的，只包含1到n之间的数字。
返回建立目标数组的操作。保证你的答案是唯一的。
约束条件：
1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target 是严格增加的。

示例1:
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]

示例2:
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]

示例3:
Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.

示例4:
Input: target = [2,3,4], n = 4
Output: ["Push","Pop","Push","Push","Push"]
*/
#include "leetcode.h"

namespace q1441
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> target {1,3};
        int n = 3;
        vector<string> ret {"Push","Push","Pop","Push"};
        CHECK_RET(comp_vector(ret, slt.buildArray(target, n)));
    }

    {
        vector<int> target {1,2,3};
        int n = 3;
        vector<string> ret {"Push","Push","Push"};
        CHECK_RET(comp_vector(ret, slt.buildArray(target, n)));
    }

    {
        vector<int> target {1,2};
        int n = 4;
        vector<string> ret {"Push","Push"};
        CHECK_RET(comp_vector(ret, slt.buildArray(target, n)));
    }

    {
        vector<int> target {2,3,4};
        int n = 4;
        vector<string> ret {"Push","Pop","Push","Push","Push"};
        CHECK_RET(comp_vector(ret, slt.buildArray(target, n)));
    }

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8 MB, less than 100.00% 
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> ret;
        for (int i = 1, j = 0; i <= n && j < len; ++i) {
            if (i == target[j]) {
                ret.push_back("Push");
                ++j;
            } else {
                ret.push_back("Push");
                ret.push_back("Pop");
            }
        }
        return ret;
    }
};
TEST(Q1441, Solution) {EXPECT_TRUE(run_testcases<Solution>());}    
} // namespace q1441
