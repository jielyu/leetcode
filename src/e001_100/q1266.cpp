/*
#面试刷题# 第0009期
#Leetcode# Q1266 访问所有点的最短时间
难度：低
在一个平面上，有n个点的整数坐标为points[i] = [xi，yi]。您的任务是找到访问所有地点的最短时间（以秒为单位）。
您可以按照以下规则移动：
1. 您始终可以在一秒钟内垂直，水平移动一个单位或对角线移动（这意味着在一秒钟内垂直移动一个单位，水平移动一个单位）。
2. 您必须按与它们在“出现”中出现的顺序相同的顺序访问这些点。在一个平面上，有n个具有整数坐标的点[i] = [xi，yi]。您的任务是找到访问所有地点的最短时间（以秒为单位）。
约束条件：
(a) points.length == n
(b) 1 <= n <= 100
(c) points[i].length == 2
(d) -1000 <= points[i][0], points[i][1] <= 1000

例1:
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
例2:
Input: points = [[3,2],[-2,2]]
Output: 5
*/
#include "leetcode.h"

namespace q1266{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    // example 01
    {
        vector<vector<int>> pts{{1,1},{3,4},{-1,0}};
        if (slt.minTimeToVisitAllPoints(pts) != 7) {return false;}
    }
    // example 02
    {
        vector<vector<int>> pts{{3,2},{-2,2}};
        if (slt.minTimeToVisitAllPoints(pts) != 5) {return false;}
    }

    // succ
    return true;
}

class Solution {
public:
    // 12ms, faster than 50.31%
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int npt = points.size();
        if (npt < 2) {
            return 0;
        }
        int sum = 0, x_diff=0, y_diff=0;
        for (int i=1; i<npt; ++i) {
            x_diff = abs(points[i][0] - points[i-1][0]);
            y_diff = abs(points[i][1] - points[i-1][1]);
            sum += max(x_diff, y_diff);
        }
        return sum;
    }
};
TEST(Q1266, Solution) {EXPECT_EQ(q1266::run_testcases<q1266::Solution>(), true);}

};