
/*
#LeetCode# Q0051 N皇后问题
难度：高
n-皇后之谜是在n×n的棋盘上放置n个皇后，使两个皇后不能互相攻击的问题。

给出一个整数n，返回n-皇后之谜的所有不同的解。

每个解都包含一个不同的棋盘配置，其中'Q'和'.'分别表示一个皇后和一个空位。

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
#include "leetcode.h"

namespace q0051
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// 回溯法
// Runtime: 12 ms, faster than 53.90%
// Memory Usage: 7.3 MB, less than 87.12%
class Solution {
private:
void _bt(int n, int row, vector<bool> & c_flag, vector<bool> & l_flag, 
             vector<bool> & r_flag, vector<string> & ans, vector<vector<string>> & ret) {
    // 所有行都安排完成，接受一个新的解决方案
    if (row == n) {ret.push_back(ans);}
    // 用于存储一行的安排情况
    string row_ans(n, '.');
    for (int i = 0; i < n; ++i) {
        // 用于索引左右对角线标志
        int l_idx = row + i, r_idx = (row-i < 0) ? (2*n + row - i) : (row - i);
        if (c_flag[i] || l_flag[l_idx] || r_flag[r_idx]) {continue;}
        // 设置当前行的设置
        row_ans[i] = 'Q';
        c_flag[i] = true;
        ans.push_back(row_ans);
        l_flag[l_idx] = true;
        r_flag[r_idx] = true;
        // 递归设置下一行
        _bt(n, row+1, c_flag, l_flag, r_flag, ans, ret);
        // 清理当前行
        l_flag[l_idx] = false;
        r_flag[r_idx] = false;
        ans.pop_back();
        c_flag[i] = false;
        row_ans[i] = '.';
    }
}
    
public:
    vector<vector<string>> solveNQueens(int n) {
        // 用于存储一个复合要求的解决方案
        vector<string> ans;
        // 用于存储所有符合要求的解决方案
        vector<vector<string>> ret;
        // 用于存储列是否被安排的标志，初始化为false
        // c_flag用于标记列占用，l_flag用于标记左对角线占用，r_flag用于标记右对角线占用
        vector<bool> c_flag(n, false), l_flag(2*n, false), r_flag(2*n, false);
        // 从第0行开始，递归安排每一行
        if (n > 0) {_bt(n, 0, c_flag, l_flag, r_flag, ans, ret);}
        // 返回最终的结果
        return ret;
    }
};

} // namespace q0051
