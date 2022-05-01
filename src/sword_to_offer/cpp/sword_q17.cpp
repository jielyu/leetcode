
/*
#剑指Offer# Q17 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表，并使新链表中的元素仍然是递增排序。


*/
#include "leetcode.h"

namespace sword_q17
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> v1 {1,4,6,8}, v2{2,4,7,9}, ret {1,2,4,4,6,7,8,9};
        auto head1 = create_list(v1);
        auto head2 = create_list(v2);
        auto merge_head = slt.merge(head1, head2);
        auto ret_vec = list2vector(merge_head);
        delete_list(merge_head);
        CHECK_RET(comp_vector(ret_vec, ret));
    }

    return true;
}

class Solution {
public:
    ListNode * merge(ListNode * head1, ListNode * head2) {
        if (!head1) {return head2;}
        if (!head2) {return head1;}
        // 获取合并后的头节点
        ListNode * merge_head = nullptr;
        if (head1->val < head2->val) {
            merge_head = head1;
            merge_head->next = merge(head1->next, head2);
        } else {
            merge_head = head2;
            merge_head->next = merge(head1, head2->next);
        }
        return merge_head;
    }
};
TEST(Sword, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q17
