/*
#面试刷题# 第0058期
#Leetcode# Q1353 可以参加的最大活动数
难度：中
给定一系列事件，其中events [i] = [startDayi，endDayi]。
每个事件我都从startDayi开始，到endDayi结束。
您可以在d的任何一天（startTimei <= d <= endTimei）参加活动i。
请注意，您在任何时间只能参加一个活动。返回您可以参加的最大活动数。
约束条件：
(a) 1 <= events.length <= 10^5
(b) events[i].length == 2
(c) 1 <= events[i][0] <= events[i][1] <= 10^5

例1:
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

例2:
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4

例3:
Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4

例4:
Input: events = [[1,100000]]
Output: 1

例5:
Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7
*/
#include "leetcode.h"

namespace q1353{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
private:
    static bool _comp_func(const vector<int> & a, 
                           const vector<int> & b) {
        return a[1] < b[1];
    }
    
public:
    // Runtime: 228 ms, faster than 92.22%
    // Memory Usage: 44.5 MB, less than 100.00%
    int maxEvents(vector<vector<int>>& events) {
        // sort by increasing order of the end day
        sort(events.begin(), events.end(), this->_comp_func);
        // check all events
        int num_events = events.size(), ret = 0;
        vector<bool> used(events[num_events-1][1] + 1, false);
        for (auto & e : events) {
            // find a free day to arrange this event
            for (int i = e[0]; i<=e[1]; ++i) {
                if (used[i]) {
                    continue; // to check the next day
                }
                used[i] = true;
                ++ret;
                break; // arrange current event completely
            }
        }
        return ret;
    }
};
};