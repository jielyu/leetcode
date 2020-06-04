
/*
#LeetCode# Q0072 编辑距离
难度：高

给出两个单词word1和word2，求出将word1转换为word2所需的最小操作数。

你可以对一个单词进行以下3个操作。

插入一个字符
删除一个字符
替换一个字符

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/
#include "leetcode.h"

namespace q0072
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

} // namespace q0072
