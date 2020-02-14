/*
#面试刷题# 第0039期
#Leetcode# Q1311 获取朋友观看的视频
难度：中
有n个人，每个人都有一个介于0到n-1之间的唯一ID。给定数组watchedVideos和friends，
其中watchedVideos [i]和friends [i]分别包含id = i的人的观看视频列表和朋友列表。
级别1的视频是您的朋友观看的所有视频，级别2的视频是您的朋友的观看的所有视频，依此类推。
通常，视频级别k都是由最短路径恰好等于k的人观看的视频。根据您的ID和视频级别，
返回按其频率排序（递增）的视频列表。对于相同频率的视频，请按从小到大的字母顺序排列。
约束条件：
(a) n == watchedVideos.length == friends.length
(b) 2 <= n <= 100
(c) 1 <= watchedVideos[i].length <= 100
(d) 1 <= watchedVideos[i][j].length <= 8
(e) 0 <= friends[i].length < n
(f) 0 <= friends[i][j] < n
(g) 0 <= id < n
(h) 1 <= level < n
(i) 如果friends[i] 包含 j, 则 friends[j] 包含 i
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Comp {
private:
   unordered_map<string, int> * _dict;
public:
    Comp(unordered_map<string, int> * dict) {
        _dict = dict;
    }
    
    bool operator()(const string & a, const string & b) {
        if ((*_dict)[a] == (*_dict)[b]) {
            return a < b;
        }
        return (*_dict)[a] < (*_dict)[b];
    }
};

class Solution {
public:
    // Runtime: 156 ms, faster than 15.49%
    // Memory Usage: 27.7 MB, less than 100.00%
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        // bfs, get all level-th friends
        unordered_set<int> lf, notlf, oldf(friends[id].begin(), friends[id].end()), newf;
        notlf.insert(id);
        while (level) {
            newf.clear();
            if (1 != level) {
                for (auto & i : oldf) {
                    if (i == id) {
                        continue;
                    }
                    notlf.insert(i);
                    for (auto & k : friends[i]) {
                        newf.insert(k);
                    }
                }
                oldf = newf;
            } else {
                for (auto & i : oldf) {
                    if (!notlf.count(i)) {
                        lf.insert(i);
                    }
                } 
            }
            --level;
        }
        
        // count frequency of movies
        unordered_map<string, int> dict;
        for (auto & v : lf) {
            for (auto & m : watchedVideos[v]) {
                ++dict[m];
            }
        }
        
        vector<string> ret;
        ret.reserve(dict.size());
        for (auto & kv : dict) {
            // std::cout << kv.first << "," << kv.second << std::endl;
            ret.push_back(kv.first);
        }
        // sort
        Comp comp(&dict);
        sort(ret.begin(), ret.end(), comp);
        return ret;
    }
};