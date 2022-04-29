
/*
#LeetCode# Q0038 数和说
难度：低
数说序列是指整数的前五项的整数序列，具体如下。

1.     1
2.     11
3.     21
4.     1211
5.     111221
1被读成 "一个1 "或11。
11被读成 "两个1 "或21。
21被读成 "一个2，然后是一个1 "或1211。

给出一个整数n，其中1≤n≤30的整数n，生成数说序列的第n个项。你可以递归地这样做，换句话说，从前一个成员读出的数字，计数相同数字的组数。

注意：整数序列的每个项将被表示为一个字符串。

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
*/
#include "leetcode.h"

namespace q0038
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

} // namespace q0038
