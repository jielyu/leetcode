
/*
#剑指Offer# Q15 链表中的倒数第k个节点
输入一个链表，输出链表中的倒数第k个节点。从1开始计数，比如倒数第1个就是最后一个节点。

*/
#include "leetcode.h"

namespace sword_q15
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> arr {1,2,3,4,5,6};
        auto head = create_list(arr);
        auto ret = slt.lastKNode(head, 3);
        delete_list(head);
        CHECK_RET(4 == ret);
    }

    {
        vector<int> arr {1,2,3,4,5,6};
        auto head = create_list(arr);
        auto ret = slt.lastKNode(head, 1);
        delete_list(head);
        CHECK_RET(6 == ret);
    }

    {
        vector<int> arr {1,2,3,4,5,6};
        auto head = create_list(arr);
        auto ret = slt.lastKNode(head, 7);
        delete_list(head);
        CHECK_RET(-1 == ret);
    }

    return true;
}

class Solution {
public:
    int lastKNode(ListNode * head, int k) {
        if (!head) {return -1;}
        ListNode * low = head, * high = head;
        // 先走k步长度不够则返回-1，注意条件是走k-1步
        for (int i = 0; i < k - 1; ++i) {
            if (high->next) {high = high->next;}
            else {return -1;}
        }
        while (high->next != 0) {
            low = low->next;
            high = high->next;
        }
        return low->val;
    }
};
TEST(SwordQ15, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q15
