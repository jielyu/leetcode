
/*
#LeetCode# Q0013 罗马数字转换成整数
难度：低
罗马数字用七个不同的符号来表示。I、V、X、L、C、D和M。

符号值
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
例如，二是用罗马数字写成二，只是两个一加在一起。12写成，XII，简单来说就是X+II。数字二十七写成，XXVII，就是XX+V+II。

罗马数字通常从左至右从大到小写成。然而，四的数字并不是IIII。相反，四的数字是写成了四。因为1在5的前面，所以我们把它减去就成了4。同样的原理也适用于数字九，它写成了九。有六种情况下使用了减法。

I可以放在v（5）和x（10）之前，使4和9。
x可以放在l（50）和c（100）之前，使40和90。
C可以放在D(500)和M(1000)之前，使400和900。
给出一个罗马数字，将其转换为整数。输入量保证在1到3999之间。

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include "leetcode.h"

namespace q0013
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
思路：遇到字符先加进去，碰到后面一个比当前一个大的就减2倍即可。
*/

class Solution {
public:
    void func();
};

} // namespace q0013
