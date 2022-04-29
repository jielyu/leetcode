
/*
#LeetCode# Q0052 N皇后问题2
难度：高
n-皇后之谜是在n×n的棋盘上放置n个皇后，使两个皇后不能互相攻击的问题。
给定一个整数n，返回n个整数，返回n个谜题的不同解数。

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
#include "leetcode.h"

namespace q0052
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// 回溯法
// Runtime: 4 ms, faster than 83.83%
// Memory Usage: 6.3 MB, less than 43.82%
class Solution {
private:
void _bt(int n, int row, vector<bool> & c_flag, vector<bool> & l_flag, 
             vector<bool> & r_flag, int & ret) {
    // 所有行都安排完成，接受一个新的解决方案
    if (row == n) {++ret;}
    // 用于存储一行的安排情况
    for (int i = 0; i < n; ++i) {
        // 用于索引左右对角线标志
        int l_idx = row + i, r_idx = (row-i < 0) ? (2*n + row - i) : (row - i);
        // 跳过不符合规则的位置
        if (c_flag[i] || l_flag[l_idx] || r_flag[r_idx]) {continue;}
        // 设置当前行的设置
        c_flag[i] = true;
        l_flag[l_idx] = true;
        r_flag[r_idx] = true;
        // 递归设置下一行
        _bt(n, row+1, c_flag, l_flag, r_flag, ret);
        // 清理当前行
        l_flag[l_idx] = false;
        r_flag[r_idx] = false;
        c_flag[i] = false;
    }
}
    
public:
    int totalNQueens(int n) {
        // 用于存储所有符合要求的解决方案
        int ret = 0;
        // 用于存储列是否被安排的标志，初始化为false
        // c_flag用于标记列占用，l_flag用于标记左对角线占用，r_flag用于标记右对角线占用
        vector<bool> c_flag(n, false), l_flag(2*n, false), r_flag(2*n, false);
        // 从第0行开始，递归安排每一行
        if (n > 0) {_bt(n, 0, c_flag, l_flag, r_flag, ret);}
        // 返回最终的结果
        return ret;
    }
};

} // namespace q0052
