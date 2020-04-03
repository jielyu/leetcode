/*
#面试刷题# 第0016期
#Leetcode# Q1338 将数组大小减小一半
难度：中
给定数组arr。您可以选择一组整数，并删除数组中所有这些整数的出现。
返回集合的最小大小，以便删除数组的至少一半整数。
约束条件：
(a) 1 <= arr.length <= 10^5
(b) arr.length is even.
(c) 1 <= arr[i] <= 10^5
 
例1:
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size greater than half of the size of the old array.
例2:
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
例3:
Input: arr = [1,9]
Output: 1
例4:
Input: arr = [1000,1000,3,7]
Output: 1
例5：
Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5
*/

class Solution {
public:
    // Runtime: 340 ms, faster than 31.81%
    // Memory Usage: 40.3 MB, less than 100.00%
    int minSetSize(vector<int>& arr) {
        // counter all unique numbers
        //map<int, int> cnt_map;
        // Runtime: 248 ms, faster than 60.92%
        // Memory Usage: 37 MB, less than 100.00%
        unordered_map<int, int> cnt_map;
        for (auto & v : arr) {
            ++cnt_map[v];
        }
        // sort counters descently
        vector<int> cnt_vec;
        cnt_vec.reserve(cnt_map.size());
        for (auto & kv : cnt_map) {
            cnt_vec.push_back(kv.second);
        }
        sort(cnt_vec.rbegin(), cnt_vec.rend());
        // count the largest counters
        int s = arr.size();
        int half = s % 2 == 0 ? s/2 : 1 + s/2;
        int ret = 0;
        for (auto & c : cnt_vec) {
            ++ret;
            half -= c;
            if (half <= 0) {
                break;
            }
        }
        return ret;
    }
};