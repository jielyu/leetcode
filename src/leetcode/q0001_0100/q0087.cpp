
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


// untime: 8 ms, faster than 83.50% o
// Memory Usage: 9.1 MB, less than 68.97%
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {return true;}
        int len = s1.size();
        if (s2.size() != len) {return false;}
        // 检查字母的统计直方图
        const int MAX_NUM = 26;
        int hist[MAX_NUM] = {0};
        for (int i = 0; i < len; ++i) {
            hist[s1[i] - 'a']++;
            hist[s2[i] - 'a']--;
        }
        for (int i = 0; i < MAX_NUM; ++i) {
            if (hist[i] != 0) {return false;}
        }
        // 逐个长度试探
        for (int i = 1; i <= len-1; ++i) {
            auto s1_left = s1.substr(0, i), s1_right = s1.substr(i);
            auto s2_left = s2.substr(0, i), s2_right = s2.substr(i);
            if (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right)) {
                return true;
            } 
            s2_right = s2.substr(len-i); 
            s2_left = s2.substr(0,len-i);
            if (isScramble(s1_left, s2_right) && isScramble(s1_right, s2_left)) {
                return true;
            } 
        }
        return false;
    }
};

} // namespace q0087
