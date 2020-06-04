
/*
#LeetCode# Q0068 文本矫正
难度：高

给出一个单词数组和宽度maxWidth，将文本格式化，使每行都有正好的maxWidth字符，并且完全（左右）对齐。

你应该以贪婪的方式来包装你的单词，也就是说，在每行中尽可能多地包装单词。在必要的时候，可以垫上额外的空格 '''，这样每行的最大宽度字符数就会完全一致。

字与字之间的多余空格应尽可能平均分布。如果一行中的空格数没有平均分配，左边的空位将比右边的空位多。

对于最后一行文字，应左对齐，字与字之间不加空格。

注意事项。

一个字的定义是指仅由非空格字符组成的字符序列。
每个字的长度保证大于0且不超过maxWidth。
输入的数组字至少包含一个字。

Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
#include "leetcode.h"

namespace q0068
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

} // namespace q0068
