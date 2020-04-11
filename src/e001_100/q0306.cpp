/*
#面试刷题# 第94期
#Leetcode# Q0306 加性数字
加性数字是一个字符串，其数字可以形成加性数字序列。
有效的加性数字序列应至少包含三个数字。 除前两个数字外，
序列中的每个后续数字必须为前两个数字的和。
给定一个仅包含数字“ 0”-“ 9”的字符串，编写一个函数以确定它是否为加数。
注意：加法序列中的数字不能有前导零，因此序列1、2、03或1、02、3无效。
约束条件：
num仅由数字“ 0”-“ 9”组成。
1 <=数字长度<= 35

示例1:
Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

示例2:
Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199

Solution From: https://leetcode.com/problems/additive-number/discuss/507073/C%2B%2B-Simple-DFS-Beats-100-Time-100-space-With-Explanation
*/
#include "leetcode.h"

namespace q0306
{
    
template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        if (true != slt.isAdditiveNumber("112358")) {return false;}
    }

    // example 02
    {
        if (true != slt.isAdditiveNumber("199100199")) {return false;}
    }

    return true;
}


// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00%
class Solution {
private:
    bool _is_valid(long & first, long & second, int start, string & num) {
        int n = num.size();
        long third = 0;
        if (start == n) {return true;}
        for (int i = start; i < n; ++i) {
            third *= 10;
            third += (int)(num[i] - '0');
            // find the third number
            if (third == first + second) {
                // the last char or the next number do not start with 0
                if ((i+1==n) || ('0' != num[i+1])) {
                    return _is_valid(second, third, i+1, num);    
                }
            } 
            // do not exist the third number
            else if (third > first + second) {
                return false;
            }
        }
        return false;
    }
    
public:
    bool isAdditiveNumber(string num) {
        long first = 0, second = 0, n = num.size();
        int first_len = n / 2;
        // special case
        if ("000" == num) {return true;}
        // check all posible for first
        for (int i = 0; i < first_len; ++i) {
            // the first number cannot start with 0 if it is not zero
            if (i != 0 && 0 == first) {return false;}
            first *= 10; first += (int)(num[i] - '0');
            second = 0;
            // check all posible for second
            for (int j = i + 1; j-i < n-j; ++j) {
                // the second number cannot start with 0
                if ((0 == second) && (j > i+1)){break;}
                second *= 10; second += (int)(num[j] - '0');
                // the next number cannot start with 0
                if ((j-i < n-j-i) && ('0' == num[j+1])) {continue;}
                // check the third number
                if (_is_valid(first, second, j+1, num)) {return true;}
            }
        }
        return false;
    }
};
TEST(Q0306, Solution) {EXPECT_EQ(q0306::run_testcases<q0306::Solution>(), true);}

}; // namespace q0306
