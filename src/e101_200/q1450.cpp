/*
#面试刷题# 第126期
#LeetCode# Q1450 在某一时间做家庭作业的学生人数
难度：低
给定两个整数组startTime和endTime和一个整数组queryTime。
第i个学生在startTime[i]时间开始做作业，在endTime[i]时间完成作业。
返回在时间queryTime时做作业的学生人数。更正式地说，
返回queryTime位于区间[startTime[i], endTime[i]]]中的学生人数。
约束条件：
startTime.length == endTime.length
1 <= startTime.length <= 100
1 <= startTime[i] <= endTime[i] <= 1000
1 <= queryTime <= 1000

示例1:
Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
Output: 1
Explanation: We have 3 students where:
The first student started doing homework at time 1 and finished at time 3 and wasn't doing anything at time 4.
The second student started doing homework at time 2 and finished at time 2 and also wasn't doing anything at time 4.
The third student started doing homework at time 3 and finished at time 7 and was the only student doing homework at time 4.

示例2:
Input: startTime = [4], endTime = [4], queryTime = 4
Output: 1
Explanation: The only student was doing their homework at the queryTime.

示例3:
Input: startTime = [4], endTime = [4], queryTime = 5
Output: 0

示例4:
Input: startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
Output: 0

示例5:
Input: startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
Output: 5
*/
#include "leetcode.h"

namespace q1450
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> startTime {1,2,3}, endTime {3,2,7};
        int queryTime = 4;
        CHECK_RET(1 == slt.busyStudent(startTime, endTime, queryTime));
    }

    {
        vector<int> startTime {4}, endTime {4};
        int queryTime = 4;
        CHECK_RET(1 == slt.busyStudent(startTime, endTime, queryTime));
    }

    {
        vector<int> startTime {4}, endTime {4};
        int queryTime = 5;
        CHECK_RET(0 == slt.busyStudent(startTime, endTime, queryTime));
    }

    {
        vector<int> startTime {1,1,1,1}, endTime {1,3,2,4};
        int queryTime = 7;
        CHECK_RET(0 == slt.busyStudent(startTime, endTime, queryTime));
    }

    {
        vector<int> startTime {9,8,7,6,5,4,3,2,1}, endTime {10,10,10,10,10,10,10,10,10};
        int queryTime = 5;
        CHECK_RET(5 == slt.busyStudent(startTime, endTime, queryTime));
    }

    return true;
}

// Runtime: 8 ms, faster than 67.28%
// Memory Usage: 11.1 MB, less than 100.00%
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ret = 0, len = startTime.size();
        for (int i = 0; i < len; ++i) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                ++ret;
            }
        }
        return ret;
    }
};   
TEST(Q1450, Solution) {EXPECT_TRUE(run_testcases<Solution>());} 
} // namespace q1450
