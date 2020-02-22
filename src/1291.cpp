/*
#面试刷题# 第0053期
#Leetcode# Q1291 顺序数字
难度：低
当且仅当数字中的每个数字都比前一个数字大一位时，整数才具有连续数字。
返回[low，high]范围内（包括连续数字）的所有整数的排序列表。
约束条件：
(a) 10 <= low <= high <= 10^9

例1:
Input: low = 100, high = 300
Output: [123,234]

例2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Runtime: 0 ms, faster than 100.00%
    // Runtime: 0 ms, faster than 100.00%
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        for (int i = 1; i <= 8; ++i) {
            int n = i, digit = i;
            while(n <= high) {
                // generate digits
                ++digit;
                if (digit >= 10) {
                    break;
                }
                // generate number
                n = n * 10 + digit;
                if (n >= low && n <= high) {
                    ret.push_back(n);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};