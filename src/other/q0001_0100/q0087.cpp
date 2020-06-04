
/*
#LeetCode# Q0087 加扰字符串
难度：高

给定字符串s1，我们可以通过将其递归划分为两个非空子字符串将其表示为二叉树。

以下是s1 =“ great”的一种可能表示形式：
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

要对字符串进行加扰，我们可以选择任何非叶子节点并交换其两个子节点。

例如，如果我们选择节点“ gr”并交换其两个子节点，则它将生成一个加扰的字符串“ rgeat”。

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

我们说“ rgeat”是“ great”的加扰字符串。

同样，如果我们继续交换节点“ eat”和“ at”的子代，则会生成一个加扰的字符串“ rgtae”。

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

我们说“ rgtae”是“ great”的加扰字符串。

给定两个长度相同的字符串s1和s2，请确定s2是否为s1的加扰字符串。

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false


*/
#include "leetcode.h"

namespace q0087
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

} // namespace q0087
