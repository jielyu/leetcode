/*
#剑指Offer# Q05 从尾到头打印链表

*/
#include "leetcode.h"

namespace sword_q05
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> input {1,2,3,4,5}, ret {5,4,3,2,1};
        auto head = create_list(input);
        auto check = comp_vector(ret, slt.printFromTail(head));
        delete_list(head);
        CHECK_RET(check);
    }

    return true;
}

class Solution{
private:
    void _print(ListNode * head, vector<int> & ret) {
        if (head) {
            if (head->next) {
                _print(head->next, ret);
            }
            ret.push_back(head->val);
        }
    }
public:
    vector<int> printFromTail(ListNode * head) {
        vector<int> ret;
        _print(head, ret);
        return ret;
    }
};
TEST(SwordQ05, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q05