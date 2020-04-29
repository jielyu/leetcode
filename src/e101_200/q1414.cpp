/*
#面试刷题# 第0101期
#Leetcode# Q1414 找出和为K的斐波那契数的最小个数
难度：中
给定一个数k，返回其总和等于k的斐波那契数的最小值，一个斐波那契数是否可以多次使用。
斐波那契数的定义为。
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ，对于 n > 2。
可以保证，对于给定的约束，我们总是可以找到这样的斐波那契数和k。
约束条件：
1 <= k <= 10^9

示例1:
Input: k = 7
Output: 2 
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
For k = 7 we can use 2 + 5 = 7.

示例2:
Input: k = 10
Output: 2 
Explanation: For k = 10 we can use 2 + 8 = 10.

示例3:
Input: k = 19
Output: 3 
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
*/
#include "leetcode.h"

namespace q1414 {

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(2 == slt.findMinFibonacciNumbers(7));
    CHECK_RET(2 == slt.findMinFibonacciNumbers(10));
    CHECK_RET(3 == slt.findMinFibonacciNumbers(19));

    return true;
}

// Runtime: 4 ms, faster than 79.64%
// Memory Usage: 6.5 MB, less than 100.00% 
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        // compute fibonacci
        vector<int> fib{1,1};
        for (int i=0; fib[i] + fib[i+1] <= k; ++i) {
            fib.push_back(fib[i] + fib[i+1]);
        }
        // search answer starting from the bigger 
        int ret = 0;
        for (auto iter = fib.rbegin(); iter != fib.rend(); ++iter) {
            if (*iter > k) {continue;}
            k -= *iter;
            ++ret;
            if(0 == k) {break;}
        }
        return ret;
    }
};
TEST(Q1414, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// @Tiabeanie2
class Solution02 {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibos = {1, 1};
        while (fibos.back() < 1e9)
        {
            fibos.push_back(fibos.back() + fibos[fibos.size() - 2]);
        }
       
        int ans = 0;
        while (k > 1)
        {
            auto it = std::lower_bound(fibos.begin(), fibos.end(), k);
            if (*it == k)
            {
                ans ++;
                break;
            }
           
            --it;
            ans ++;
            k -= *it;
        }
       
        if (k == 1) ans ++;        
        return ans;
    }
};
TEST(Q1414, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
}; // nam;espace q1414
