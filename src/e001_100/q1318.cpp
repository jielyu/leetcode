/*
#面试刷题# 第0034期
#Leetcode# Q1318 使a OR b等于b的最小翻转
难度：中
给定3个正数，数字a，b和c。返回进行a和b的某些位所需的最小翻转（a OR b == c）。 （按位或运算）。
翻转操作包括将任何单个位1更改为0或将其二进制表示中的位0更改为1。
约束条件：
(a) 1 <= a <= 10^9
(b) 1 <= b <= 10^9
(c) 1 <= c <= 10^9

例1:
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

例2:
Input: a = 4, b = 2, c = 7
Output: 1

例3:
Input: a = 1, b = 2, c = 3
Output: 0
*/

class Solution {
public:
    // Runtime: 4 ms, faster than 56.37% 
    // Memory Usage: 8.3 MB, less than 100.00%
    int minFlips(int a, int b, int c) {
        int ret = 0, abit = 0, bbit = 0, cbit = 0;
        while(a || b || c) {
            abit = a & 1;
            bbit = b & 1;
            cbit = c & 1;
            // std::cout<<abit<<","<<bbit<<","<<cbit<<std::endl;
            if ((abit | bbit) != cbit) {
                ret += abit + bbit < 2 ? 1 : 2;
                // std::cout<<(abit|bbit)<<std::endl;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ret;
    }
};