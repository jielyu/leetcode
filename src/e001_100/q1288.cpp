/*
#面试刷题# 第0012期
#Leetcode# Q1288 移除被覆盖的区间
难度：中
给定一列区间 intervals，移除其中可以被任何其他区间覆盖的区间。
定义区间(a,b)能被区间(c,d)覆盖的只在c<=a并且d>=b条件小成立。
任务完成之后返回剩余区间的个数。
约束条件：
(a) 1 <= intervals.length <= 1000
(b) 0 <= intervals[i][0] < intervals[i][1] <= 10^5
(c) intervals[i] != intervals[j] for all i != j

例1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
*/

#include "leetcode.h"

namespace q1288{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<vector<int>> intervals {{1,4},{3,6},{2,8}};
        if (2 != slt.removeCoveredIntervals(intervals)) {return false;}
    }

    // succ
    return true;
}
// build a functor
class Comp {
    public:
    bool operator()(vector<int> & a, vector<int> & b) {
        return a[0] < b[0];
    }
};

class Solution {
public:
    // 24ms, faster than 75.58%
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort intervals by the first coordinate
        Comp comp;
        sort(intervals.begin(), intervals.end(), comp);
        // count intervals
        int len = intervals.size();
        int cnt = 1; // counter the first interval
        for (int i=0, j=1; i<len && j<len; ++j) {
            // meet the one cannot be covered  
            if (intervals[i][1] < intervals[j][1]) {
                i = j;
                ++cnt;
            }
        }
        return cnt;
    }
};
TEST(Q1288, Solution) {EXPECT_EQ(q1288::run_testcases<q1288::Solution>(), true);}
};