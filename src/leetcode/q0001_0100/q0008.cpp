
/*
#LeetCode# Q0008 字符串到整数
难度：中
实现 atoi，将字符串转换为整数。

该函数首先丢弃尽可能多的空格字符，直到找到第一个非空格字符。然后，从这个字符开始，取一个可选的初始加号或减号，后面是尽可能多的数字，并将其解释为一个数值。

字符串中可以包含构成积分数之后的其他字符，这些字符被忽略，对这个函数的行为没有影响。

如果str中的第一个非空格字符序列不是有效的积分数，或者因为str是空的或者只包含空格字符，所以不存在这样的序列，则不进行转换。

如果不能进行有效的转换，则返回一个零值。

注意：
(1) 只有空格字符' '被认为是白格字符。
(2) 假设我们所处理的环境只能存储32位有符号整数范围内的整数，那么，我们将返回0值。[−231, 231 − 1]. 如果数值不在可表示的值范围内，则返回INT_MAX (-231 - 1) 或 INT_MIN (-231)。

Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.

*/
#include "leetcode.h"

namespace q0008
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
思路：先找到以第一个有效的字符位置，并判断正负，然后再进行转换，需要注意溢出，所以结果存储在long类型变量中
*/

class Solution {
public:
    void func();
};

} // namespace q0008
