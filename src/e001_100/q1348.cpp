/*
#面试刷题# 第0030期
#Leetcode# Q1348 每个频率的推文计数
难度：中
实现支持两种方法的TweetCounts类：
1. recordTweet(string tweetName, int time)
保存推文名并记录时间，单位秒。
2. getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
(1 )返回从开始时间（以秒为单位）开始到结束时间（以秒为单位）开始的每分钟，小时或每天（取决于频率）给定tweetName出现的总数。
(2) freq始终是minute，hour或day，表示获取给定tweetName的总出现次数的时间间隔。
第一个时间间隔始终从startTime开始，因此时间间隔为
[startTime, startTime + delta*1>,  
[startTime + delta*1, startTime + delta*2>, 
[startTime + delta*2, startTime + delta*3>, ... , 
[startTime + delta*i, min(startTime + delta*(i+1), endTime + 1)>
对于一些非负数i和delta,取决于freq
约束条件：
(a) 同时考虑到recordTweet和getTweetCountsPerFrequency，最多将进行10000次操作
(b) 0 <= time, startTime, endTime <= 10^9
(c) 0 <= endTime - startTime <= 10^4

例1:
["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

Output
[null,null,null,null,[2],[2,1],null,[4]]

Explanation
TweetCounts tweetCounts = new TweetCounts();
tweetCounts.recordTweet("tweet3", 0);
tweetCounts.recordTweet("tweet3", 60);
tweetCounts.recordTweet("tweet3", 10);                             // All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]. The frequency is per minute (60 seconds), so there is one interval of time: 1) [0, 60> - > 2 tweets.
tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 1 tweet.
tweetCounts.recordTweet("tweet3", 120);                            // All tweets correspond to "tweet3" with recorded times at 0, 10, 60 and 120.
tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]. The frequency is per hour (3600 seconds), so there is one interval of time: 1) [0, 211> - > 4 tweets.
*/
#include "leetcode.h"

namespace q1348{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

// Runtime: 212 ms, faster than 61.82%
// Memory Usage: 33.4 MB, less than 100.00%
class TweetCounts {
private:
    unordered_map<string, multiset<int>> _dict;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        _dict[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int units = 86400;
        if ("hour" == freq) {
            units = 3600;
        } else if ("minute" == freq) {
            units = 60;
        }
        int len = (endTime - startTime) / units + 1;
        vector<int> ret(len);
        auto result = _dict.find(tweetName);
        if (_dict.end() != result) {
            auto & time_set = result->second;
            for (auto iter=time_set.lower_bound(startTime); 
                    time_set.end() != iter && endTime >= (*iter); ++iter) {
                ++ret[((*iter)-startTime)/units];
            }
        }
        return ret;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

};