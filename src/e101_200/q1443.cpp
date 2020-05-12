/*
#面试刷题# 第120期
#Leetcode#  Q1443 采集一棵树上所有苹果的最短时间
难度：中
给定一棵无定向树，由n个顶点组成，顶点从0到n-1，其中有一些苹果。你花1秒的时间走过树的一条边。返回从顶点0开始收集树上所有的苹果，并返回到这个顶点的最小时间（秒）。

非定向树的边缘在数组 edges 中给出，其中 edges[i] = [fromi, toi] 表示存在一条连接顶点fromi和toi的边缘。此外，还有一个布尔数组hasApple，其中hasApple[i]=true表示顶点i有一个苹果，否则，它没有任何苹果。
约束条件：
1 <= n <= 10^5
edges.length == n-1
edges[i].length == 2
0 <= fromi, toi <= n-1
fromi < toi
hasApple.length == n

示例1:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

示例2:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows. 

示例3:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0
*/
#include "leetcode.h"

namespace q1443
{
template<typename T>
bool run_testcases() {
    T slt;

    {
        int n = 7, ret = 8;
        vector<vector<int>> edges {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        vector<bool> hasApple {false,false,true,false,true,true,false};
        CHECK_RET(ret == slt.minTime(n, edges, hasApple));
    }

    {
        int n = 7, ret = 6;
        vector<vector<int>> edges {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        vector<bool> hasApple {false,false,true,false,false,true,false};
        CHECK_RET(ret == slt.minTime(n, edges, hasApple));
    }

    {
        int n = 7, ret = 0;
        vector<vector<int>> edges {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        vector<bool> hasApple {false,false,false,false,false,false,false};
        CHECK_RET(ret == slt.minTime(n, edges, hasApple));
    }

    return true;
}

// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/discuss/623679/C%2B%2B-Short-and-simple-DFS
// Runtime: 332 ms, faster than 82.67%
// Memory Usage: 60.4 MB, less than 100.00%
class Solution {
private:
    int _dfs(vector<vector<int>> & adj_list, vector<bool> & has_apple, int idx, int d, int pre) {
        int ret = 0, mid = 0;
        for (auto i : adj_list[idx]) {
            // 在树中，一个节点就能够阻断其子树回溯
            if (i != pre) {
                mid = _dfs(adj_list, has_apple, i, d+1, idx);
                // 如果idx的子树中有苹果，则mid必定大于0
                // 并且是其深度
                if (mid > 0) {ret += mid - d;}
            }
        }
        // 如果当前节点上有苹果就返回其深度
        // 如果子树上有苹果，就再加上当前节点到子树的深度
        return has_apple[idx] || ret > 0 ? ret + d : 0;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // 创建链接表
        vector<vector<int>> adj_list(n, vector<int>());
        for (auto & edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        // dfs，深度的两倍
        return 2 * _dfs(adj_list, hasApple, 0, 0, -1);
    }
}; 
TEST(Q1443, Solution) {run_testcases<Solution>();}
} // namespace q1443
