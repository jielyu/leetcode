/*
#面试刷题# 第0086期
#Leetcode# Q1401 圆和矩形重叠 
难度：中
给定一个表示为（半径，x_center，y_center）的圆和一个表示为
（x1，y1，x2，y2）的与轴对齐的矩形，其中（x1，y1）是左下角的坐标，
而（x2， y2）是矩形右上角的坐标。
如果圆形和矩形重叠，则返回True，否则返回False。
换句话说，检查是否同时存在属于圆和矩形的任何点（xi，yi）。
约束条件：
1 <= radius <= 2000
-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
x1 < x2
y1 < y2

示例1:
Input: radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0) 

示例2:
Input: radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true

示例3:
Input: radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
Output: true

示例4:
Input: radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false
*/
#include "leetcode.h"

namespace q1401{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    CHECK_RET(true == slt.checkOverlap(1,0,0,1,-1,3,1));
    CHECK_RET(true == slt.checkOverlap(1,0,0,-1,0,0,1));
    CHECK_RET(true == slt.checkOverlap(1,1,1,-3,-3,3,3));
    CHECK_RET(false == slt.checkOverlap(1,1,1,1,-3,2,-1));

    // succ
    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = x_center - max(x1, min(x_center, x2));
        int dy = y_center - max(y1, min(y_center, y2));
        return dx*dx+dy*dy <= radius*radius;
    }
};
TEST(Q1401, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
};
