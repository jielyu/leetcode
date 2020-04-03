/*
#面试刷题# 第0018期
#Leetcode# Q1334 查找阈值距离内邻居最少的城市
难度：中
有n个城市，编号从0到n-1。给定数组边，其中edge [i] = [fromi，toi，weighti]代表城市fromi和toi之间的双向和加权边，并给出整数distanceThreshold。
返回通过某些路径可到达且距离最大为distanceThreshold的城市数量最少的城市，如果有多个这样的城市，则返回数量最大的城市。
请注意，连接城市i和j的路径的距离等于沿该路径的边权重之和。
约束条件：
(a) 2 <= n <= 100
(b) 1 <= edges.length <= n * (n - 1) / 2
(c) edges[i].length == 3
(d) 0 <= fromi < toi < n
(e) 1 <= weighti, distanceThreshold <= 10^4
(f) 所有点对 (fromi, toi) 是不重复的.

例1:
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

例2:
Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
*/

class Solution {
private:
    const static int _max_node = 100;
    const static int _max_num = 100000000;
    int _dist[_max_node][_max_node];
    
    void _init_dist(vector<vector<int>> & edges) {
        // fill with the biggest number
        for (int i=0; i<_max_node; ++i) {
            for (int j=0; j<_max_node; ++j) {
                _dist[i][j] = _max_num;
            }
        }
        // fill i->j and j->i
        for (auto & vec : edges) {
            _dist[vec[0]][vec[1]] = vec[2];
            _dist[vec[1]][vec[0]] = vec[2];
        }
    }
    
    void _floyd(const int & n) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<n; ++k) {
                    if (j == k) {
                        continue;
                    }
                    int d = _dist[j][i] + _dist[i][k];
                    if (_dist[j][k] > d) {
                        _dist[j][k] = d;
                    }
                } // end of for k
            } // end of for j
        } // end of for i
    }
    
public:
    // Runtime: 32 ms, faster than 98.37% 
    // Memory Usage: 11.4 MB, less than 100.00%
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        _init_dist(edges);
        _floyd(n);
        
        int min_cnt = _max_num, tmp_cnt = 0;
        int min_id = 0;
        for (int i=0; i<n; ++i) {
            tmp_cnt = 0;
            for (int j=0; j<n; ++j) {
                if (_dist[i][j] <= distanceThreshold) {
                    ++tmp_cnt;
                }
            }
            if (min_cnt >= tmp_cnt) {
                min_cnt = tmp_cnt;
                min_id = i;
            }
        }
        return min_id;
    }
};