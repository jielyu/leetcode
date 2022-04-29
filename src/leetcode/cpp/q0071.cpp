
/*
#LeetCode# Q0071 简化路径
难度：中
给出一个文件的绝对路径(Unix-style)，简化它。或者换句话说，将其转换为标准路径。

在UNIX风格的文件系统中，句号.指的是当前目录。此外，双句号 ...将目录上移一级。

注意，返回的常规路径必须以斜线/开头，而且两个目录名之间只能有一个斜线/。另外，常规路径必须是代表绝对路径的最短的字符串。

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/
#include "leetcode.h"

namespace q0071
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

} // namespace q0071
