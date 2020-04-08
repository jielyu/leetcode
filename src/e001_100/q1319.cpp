/*
#面试刷题# 第0033期
#Leetcode# Q1319 连接网络的操作次数
难度：中
通过以太网电缆连接的n台计算机（从0到n-1）通过连接形成一个网络，
其中connection [i] = [a，b]表示计算机a和b之间的连接。
任何计算机都可以通过网络直接或间接访问任何其他计算机。
给定初始计算机网络连接。您可以在两台直接连接的计算机之间拔出某些电缆，
并将它们放在两对断开连接的计算机之间，以使其直接连接。
返回进行所有计算机连接所需的最少次数。如果不可能，则返回-1。
约束条件：
(a) 1 <= n <= 10^5
(b) 1 <= connections.length <= min(n*(n-1)/2, 10^5)
(c) connections[i].length == 2
(d) 0 <= connections[i][0], connections[i][1] < n
(e) connections[i][0] != connections[i][1]
(f) 没有重复的连接
(g) 没有通过多于一根电缆连接两台计算机

例1:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

例2:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

例3:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

例4:
Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
*/
#include "leetcode.h"

namespace q1319{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
private:
    int get_root(vector<int> & link, const int & id) {
        if (link[id] != id) {
            link[id] = get_root(link, link[id]);
        }
        // return the root id
        return link[id];
    }
public:
    // Runtime: 108 ms, faster than 81.10% 
    // Memory Usage: 31.3 MB, less than 100.00%
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> link(n, 0);
        for (int i=0; i<n; ++i) {
            link[i] = i;
        }
        // construct link according to connections
        int x = 0, y = 0, dup = 0;
        for (auto & c : connections) {
            x = get_root(link, c[0]);
            y = get_root(link, c[1]);
            if (x != y) {
                link[x] = y;
            } else {
                ++dup;
            }
        }
        // count unconnected group
        int island = 0;
        for (int i=0; i<n; ++i) {
            if (i == link[i]) {
                ++island;
            }
        }
        // only possible if dup >= island - 1
        return dup >= island-1 ? island-1 : -1;
    }
};

};