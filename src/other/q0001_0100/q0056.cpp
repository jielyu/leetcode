
/*
#LeetCode# Q0056 合并区间
难度：中
给定一个时间间隔的集合，合并所有重叠的时间间隔。

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

注意：输入类型已于2019年4月15日更改。请重置为默认代码定义，以获得新的方法签名。

*/
#include "leetcode.h"

namespace q0056
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 28 ms, faster than 66.75%
// Memory Usage: 16.9 MB, less than 62.54%
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int len = intervals.size();
        bool fused = false;
        for (int i = 0; i < len; ++i) {
            // 新区间完全在当前区间右边
            if (intervals[i][1] < newInterval[0]) {
                ret.push_back(intervals[i]);
            // 新区间完全在当前区间左边
            } else if (intervals[i][0] > newInterval[1]) {
                // 接受新区间
                if (fused==false) {
                     ret.push_back(newInterval);
                     fused = true;
                }
                // 接受当前区间
                ret.push_back(intervals[i]);
                
            } else {
                // 融合当前区间和新区间
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        if (false == fused) {
            ret.push_back(newInterval);
        }
        return ret;
    }
};

} // namespace q0056
