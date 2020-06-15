
/*
#LeetCode# Q0084 直方图中最大的矩形
难度：高

给定n个表示直方图的条高的非负整数，其中每个条的宽度为1，在直方图中找到最大矩形的面积。

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/
#include "leetcode.h"

namespace q0084
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 36 ms, faster than 16.96%
// Memory Usage: 14.1 MB, less than 44.77%
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0, len = heights.size();
        heights.push_back(0);  //为了保证最后一次运行
        stack<int> buff;
        int idx = 0;
        while (idx <= len) {
            // 如果栈不为空，并且当前数值比栈顶小
            while ((buff.size() > 0) && (heights[idx] < heights[buff.top()])) {
                // 弹出栈顶
                int top_idx = buff.top();
                buff.pop();
                // 计算top_idx指向的数值为高度的矩形，x轴长度为 idx - (buff.top+1)
                int w = buff.size() == 0 ? idx : (idx - buff.top() - 1);
                int area = heights[top_idx] * w;
                // 记录最大面积
                if (area > max_area) {max_area = area;}
            }
            // 压入新元素
            buff.push(idx);
            ++idx;
        }
        return max_area;
    }
};

} // namespace q0084
