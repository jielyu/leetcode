/*
#面试刷题# 第0004期
#Leetcode# Q1281 整数各位数字之积与之和的差
给定整数n，返回其各个数位数字乘积与数字总和之间的差。
约束条件：
(a) 1 <= n <= 10^5
例1:
Input: n = 234
Output: 15
例2:
Input: n = 4421
Output: 21
*/
#include <iostream>
using namespace std;

class Solution {
public:
    // 0ms
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        int digit = 0;
        while(0 != n) {
            digit = n % 10;
            sum += digit;
            prod *= digit;
            n /= 10;
        }
        return prod - sum;
    }
};

int main() {
    int n = 234;
    Solution slt;
    cout << slt.subtractProductAndSum(n) << endl;
    return 0;
}