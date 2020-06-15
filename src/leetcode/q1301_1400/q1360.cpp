/*
#面试刷题# 第0092期
#Leetcode# Q1360 两个日期之间的天数
难度：低
编写一个程序来计算两个日期之间的天数。
这两个日期以字符串形式给出，其格式为YYYY-MM-DD，如示例所示。
约束条件：
给定的日期是1971年至2100年之间的有效日期。

示例1:
Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1

示例2:
Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15
*/
#include "leetcode.h"

namespace q1360
{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    // example 01
    {
        string date1 = "2019-06-29", date2 = "2019-06-30";
        int ret = 1;
        if (slt.daysBetweenDates(date1, date2)!=ret) {return false;}
    }

    // example 02
    {
        string date1 = "2020-01-15", date2 = "2019-12-31";
        int ret = 15;
        if (slt.daysBetweenDates(date1, date2)!=ret) {return false;}
    }

    // succ
    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00% 
class Solution {
private:
    bool _is_leap(int year) {
        return year % 4 == 0 && (year % 400 == 0 || year % 100 != 0);
    }
    
public:
    int daysBetweenDates(string date1, string date2) {
        if(date1 > date2) {swap(date1, date2);}
        int y1 = stoi(date1.substr(0, 4)), y2 = stoi(date2.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2)), m2 = stoi(date2.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2)), d2 = stoi(date2.substr(8, 2));
        // set number of days for every month
        int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int ret = 0;
        for (int y = y1; y < y2; ++y) {
            ret += _is_leap(y) ? 366 : 365;
        }
        // minus month in start year
        int feb = _is_leap(y1) ? 29 : 28;
        for (int m = 1; m < m1; ++m) {
            ret -= m == 2 ? feb : months[m-1];
        }
        // add month in the end year
        feb = _is_leap(y2) ? 29 : 28;
        for (int m = 1; m < m2; ++m) {
            ret += m == 2 ? feb : months[m-1];
        }
        // stat day
        return ret + d2 - d1;   
    }
};
TEST(Q1360, Solution) {EXPECT_EQ(q1360::run_testcases<q1360::Solution>(), true);}

}; // namespace q1360
