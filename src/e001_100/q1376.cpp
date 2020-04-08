/*
#面试刷题# 第0062期
#Leetcode# Q1376 知所有员工所需的时间
难度：中
公司有n名员工，每个员工的唯一ID从0到n-1。
公司的负责人是具有headID的员工。
每个员工在manager数组中都有一个直接经理，
其中manager[i]是第i个员工的直接经理，
manager[headID] = -1。此外，还确保从属关系具有树结构。
公司负责人希望将紧急消息通知公司所有员工。他将通知直属下属，
他们将通知其下属，依此类推，直到所有员工都知道紧急消息为止。

第i位员工需要informTime[i]分钟来通知其所有直接下属（
即，在inform[i]分钟之后，他的所有直接下属都可以开始传播新闻）。
返回将紧急消息通知所有员工所需的分钟数。
约束条件：
(a) 1 <= n <= 10^5
(b) 0 <= headID < n
(c) manager.length == n
(d) 0 <= manager[i] < n
(e) manager[headID] == -1
(f) informTime.length == n
(g) 0 <= informTime[i] <= 1000
(h) 员工i没有下线则informTime[i] == 0
(i)) 要保证所有员工都被通知到

例1:
Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.

例2:
Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.

例3:
Input: n = 7, headID = 6, manager = [1,2,3,4,5,6,-1], informTime = [0,6,5,4,3,2,1]
Output: 21
Explanation: The head has id = 6. He will inform employee with id = 5 in 1 minute.
The employee with id = 5 will inform the employee with id = 4 in 2 minutes.
The employee with id = 4 will inform the employee with id = 3 in 3 minutes.
The employee with id = 3 will inform the employee with id = 2 in 4 minutes.
The employee with id = 2 will inform the employee with id = 1 in 5 minutes.
The employee with id = 1 will inform the employee with id = 0 in 6 minutes.
Needed time = 1 + 2 + 3 + 4 + 5 + 6 = 21.

例4:
Input: n = 15, headID = 0, manager = [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6], informTime = [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
Output: 3
Explanation: The first minute the head will inform employees 1 and 2.
The second minute they will inform employees 3, 4, 5 and 6.
The third minute they will inform the rest of employees.

例5:
Input: n = 4, headID = 2, manager = [3,3,-1,2], informTime = [0,0,162,914]
Output: 1076
*/
#include "leetcode.h"

namespace q1376{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
private:
    int _dfs(const int & m, const vector<vector<int>> & r, const vector<int> & informTime) {
        int ret = 0, t = 0;
        // return 0 for leaves
        if (r[m].size() == 0) {
            return 0;
        }
        // check maximum value for all children trees
        for (auto & i : r[m]) {
            t = _dfs(i, r, informTime);
            if (t > ret) {
                ret = t; 
            }
        }
        return ret + informTime[m];
    }
    
public:
    // Runtime: 320 ms, faster than 81.55%
    // Memory Usage: 51.2 MB, less than 100.00%
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // create tree to represent relationship
        vector<vector<int>> r;
        r.resize(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                r[manager[i]].push_back(i);
            }
        }
        // get maximum time by dfs
        return _dfs(headID, r, informTime);
    }
};

};