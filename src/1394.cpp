/*
#面试刷题# 第78期
#Leetcode# Q1394 在数组中查找幸运整数
难度：低
给定一个整数数组arr，幸运整数是一个整数，其在数组中的频率等于其值。
在数组中返回一个幸运的整数。 如果有多个幸运整数，则返回其中最大的一个。 
如果没有幸运的整数，则返回-1。
约束条件：
(a) 1 <= arr.length <= 500
(b) 1 <= arr[i] <= 500

例1:
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

例2:
Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

例3:
Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.

例4:
Input: arr = [5]
Output: -1

例5:
Input: arr = [7,7,7,7,7,7,7]
Output: 7
*/

/*
提示：毫无技巧，直接上unordered_map统计即可
*/

// Runtime: 12 ms, faster than 84.83%
// Memory Usage: 10.6 MB, less than 100.00% 
class Solution {
public:
    int findLucky(vector<int>& arr) {
        // stat frequency
        unordered_map<int, int> dict;
        for (auto & v : arr) {
            ++dict[v];
        }
        // maximize lucky integer
        int ret = -1;
        for (auto & p : dict) {
            if (p.first == p.second && p.first > ret) {
                ret = p.first;
            }
        }
        return ret;
    }
};