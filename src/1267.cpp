/*
#面试刷题# 第0008期
#Leetcode# Q1267 计数能通信的服务器
难度：中
您会得到一个服务器中心的地图，用m * n整数矩阵grid表示，其中1表示在该单元上有服务器，0表示没有服务器。
如果两个服务器位于同一行或同一列，则称它们可以通信。
返回与任何其他服务器通信的服务器数量。
约束条件：
(a) m == grid.length
(b) n == grid[i].length
(c) 1 <= m <= 250
(d) 1 <= n <= 250
(e) grid[i][j] == 0 or 1

例1:
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
例2:
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
例3:
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 48ms, faster than 89.90%
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        vector<int> sum_row, sum_col;
        // add up by row
        for (auto & row : grid) {
            sum = 0;
            for (auto & c : row) {
                sum += c;
            }
            sum_row.push_back(sum);
        }
        // add up by col
        for (int j=0; j<n; ++j) {
            sum = 0;
            for (int i=0; i<m; ++i) {
                sum += grid[i][j];
            }
            sum_col.push_back(sum);
        }
        // check all servers
        sum = 0;
        vector<int> rest_row;
        // check row
        for (int i=0; i<m; ++i) {
            if (sum_row[i] >= 2) {
                sum += sum_row[i];
            } else if (sum_row[i] == 1) {
                // just find the only one
                for (int j=0; j<n; ++j) {
                    if (grid[i][j] > 0 && sum_col[j] >= 2) {
                        sum += grid[i][j];
                        break;
                    }
                }
            }
        }
        
        /* not good
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]) {
                    if (sum_row[i] >= 2 || sum_col[j] >= 2) {
                        sum += grid[i][j];
                    }
                }
            }
        }*/
        return sum;
    }
};

int main() {
    vector<vector<int>> grid{{1,1,0,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,1}};
    Solution slt;
    cout << slt.countServers(grid) << endl;
    return 0;
}