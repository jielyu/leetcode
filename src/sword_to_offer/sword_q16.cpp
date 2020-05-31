
/*
#剑指Offer# Q16 反转链表
编写一个函数，输入链表头指针，反转该链表，并输出反转后的头指针

*/
#include "leetcode.h"

namespace sword_q16
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> input {1,2,3,4,5,6}, ret = {6,5,4,3,2,1};
        auto head = create_list(input);
        auto reverse_head = slt.reverseList(head);
        auto check = comp_vector(ret, list2vector(reverse_head));
        delete_list(head);
        CHECK_RET(check);
    }

    {
        vector<int> input {1}, ret = {1};
        auto head = create_list(input);
        auto reverse_head = slt.reverseList(head);
        auto check = comp_vector(ret, list2vector(reverse_head));
        delete_list(head);
        CHECK_RET(check);
    }

    return true;
}

class Solution {
public:
    ListNode * reverseList(ListNode * head) {
        if (!head) {return nullptr;}
        ListNode * reverse_head = head;
        ListNode * tmp = nullptr;
        head = head->next;
        reverse_head->next = nullptr;
        while (head) {
            // 把head只向的节点加入到反转节点中
            tmp = reverse_head;
            reverse_head = head;
            head = head->next;
            reverse_head->next = tmp;
        }
        cout << reverse_head->val << endl;
        return reverse_head;
    }
};
TEST(SwordQ16, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q16
