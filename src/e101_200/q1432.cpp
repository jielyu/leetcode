/*
#面试刷题# 第110期
#Leetcode# Q1432 从改变一个整数中得到的最大差值
难度：中
给你一个整数。你将应用以下步骤精确地进行两次:
(1) 选取一个数字x（0 <= x <= 9）。
(2) 选取另一个数字y（0 <= y <= 9）。这个数字y可以等于x。
(3) 用y代替num的十进制表示法中所有的x的出现次数。
(4) 新的整数不能有任何前导零，新的整数也不能是0。
让a和b分别是对num进行第一次和第二次操作的结果。
返回a和b之间的最大差值。
约束条件：
1 <= num <= 10^8

示例1:
Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888

示例2:
Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8

示例3:
Input: num = 123456
Output: 820000

示例4:
Input: num = 10000
Output: 80000

示例5:
Input: num = 9288
Output: 8700
*/
#include "leetcode.h"

namespace q1432
{

template<typename T>
bool run_testcases() {
    T slt;
    CHECK_RET(888 == slt.maxDiff(555));
    CHECK_RET(8 == slt.maxDiff(8));
    CHECK_RET(820000 == slt.maxDiff(123456));
    CHECK_RET(80000 == slt.maxDiff(10000));
    CHECK_RET(8700 == slt.maxDiff(9288));
    
    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%
class Solution {
private:
int _replace_digits(string num_str, int idx, char dst) {
    char src = num_str[idx];
    for (int i = idx; i < num_str.size(); ++i) {
        if ( src == num_str[i]) {
            num_str[i] = dst;
        }
    }
    // cout << num_str << endl;
    return std::stoi(num_str);
}
public:
    int maxDiff(int num) {
        string num_str = to_string(num);
        int len = num_str.size(), a = num, b = num;
        // construct a
        for (int i = 0; i < len; ++i) {
            if (num_str[i] != '9') {
                a = _replace_digits(num_str, i, '9');
                break;
            }
        }
        // construct b
        if (num_str[0] != '1') {
            b = _replace_digits(num_str, 0, '1');
        } else {
            for (int i = 1; i < len; ++i) {
                // 不加这个条件 num_str[i] != '1' 能够得到的值更大
                if (num_str[i] != '0' && num_str[i] != '1') {
                    b = _replace_digits(num_str, i, '0');
                    break;
                }
            }
        }
        return a - b;
    }
};
TEST(Q1432, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1432
