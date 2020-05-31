
/*
#剑指Offer# Q40 数组中只出现一次的数字
一个整型数组中处理两个数值外，其他数字都出现了两次。请编写一个程序找出这两个只出现一次的数字。

*/
#include "leetcode.h"

namespace sword_q40
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
对所有元素进行异或运算，最后的结果必定不为0.找到结果中为1的位，说明那两个不同的数字在这一位上必定不同。
依据这一位将数组分成两个子数组，各自求异或，就可以得到各自只出现一次的数字。
*/

class Solution {
public:
    void func();
};

} // namespace sword_q40
