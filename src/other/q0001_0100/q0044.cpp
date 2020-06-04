
/*
#LeetCode# Q0044 通配卡匹配
难度：高
给定一个输入字符串(s)和模式(p)，实现通配符模式匹配，支持'?'和'*'。

'?' 匹配任何单个字符。
'*' 匹配任何字符序列（包括空序列）。
匹配应该覆盖整个输入字符串（而不是局部）。

注意：'*'?

s可以是空的，只包含小写字母a-z。
p可以是空的，只包含小写字母a-z，以及像 ? 或 * 这样的字符。

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
#include "leetcode.h"

namespace q0044
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
public:
    void func();
};

} // namespace q0044
