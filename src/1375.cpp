/*
#面试刷题# 第0063期
#Leetcode# Q1375 灯泡切换器III
难度：中
有一个房间，其中n个灯泡的编号从1到n，从左到右排成一排。最初，所有灯泡都关闭。
在时刻k（对于k从0到n-1），我们打开light [k]灯泡。
仅当灯泡打开并且之前的所有灯泡（左侧）也都打开时，它的颜色才会变为蓝色。
返回所有打开的灯泡为蓝色的瞬间数。
约束条件：
(a) n == light.length
(b) 1 <= n <= 5 * 10^4
(c) 灯泡的排列顺序 [1, 2, ..., n]
*/

class Solution {
public:
    // Runtime: 80 ms, faster than 92.56%
    // Memory Usage: 13 MB, less than 100.00%
    int numTimesAllBlue(vector<int>& light) {
        int high = 0, ret = 0;
        int n = light.size();
        for (int i = 0; i < n; ++i) {
            if (light[i] > high) {
                high = light[i];
            }
            if (high == i+1){
                ++ret;    
            }
        }
        return ret;
    }
};