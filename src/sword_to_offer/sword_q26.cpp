
/*
#剑指Offer# Q26 复杂链表的复制
编写一个函数复制一个复杂链表。在复杂链表中，每一个节点除了有一个next指针，还有一个sibing指针只想任意节点后者为空。

*/
#include "leetcode.h"

namespace sword_q26
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
三步完成：
(1)在每个节点后边都复制一份自己
(2)当原始节点的sibing指针不为空时，复制品的sibing也指向对应的复制品
(3)切断原始链表和复制品的链接。
*/

class Solution {
public:
    void func();
};

} // namespace sword_q26
