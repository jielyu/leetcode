/*
#面试刷题# 第0117期
#Leetcode# Q0002 两数相加
难度：中
给你两个非空的链接列表，代表两个非负数整数。这些数字按相反的顺序存储，
它们的每个节点都包含一位数。将这两个数字相加并返回为一个链接列表。
你可以假设这两个数字不包含任何前导数0，但数字0本身除外。

示例1:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/
#include "leetcode.h"

namespace q0002
{

template<typename T>
bool run_testcases() {
    T slt;

    vector<int> list1 {2,4,3}, list2 {5,6,4};
    auto * l1 = create_list(list1);
    auto * l2 = create_list(list2);
    vector<int> ret;
    ListNode * head = slt.addTwoNumbers(l1, l2);
    while(head) {
        ret.push_back(head->val);
        head = head->next;
    }
    delete_list(l1);
    delete_list(l2);

    vector<int> ans{7, 0, 8};
    CHECK_RET(comp_vector(ans, ret));
    return true;
}

// Runtime: 20 ms, faster than 98.74%
// Memory Usage: 70.3 MB, less than 5.14%
// 注意解决方案内部可能会在l1后添加节点
class Solution {
private:
        ListNode * _insertNode(ListNode * head, int val){
            if(head == NULL){
                head = new ListNode(val);
            }else{
                ListNode * it = head;
                for(;it->next!=NULL; it=it->next){}
                it->next = new ListNode(val);
            }
            return head;
        }
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * it1 = l1, * it2 = l2;
        int inc = 0, add = 0;
        ListNode * res = l1;
        while (it1 || it2) {
            add = inc;
            if(it1){ add += it1->val;}
            if(it2){ add += it2->val; it2 = it2->next;}
            //std::cout<<add<<std::endl;
            inc =  add / 10;
            add = add % 10;
            if (it1) {
                it1->val = add; 
                it1 = it1->next;
            } else {
                res = _insertNode(res, add);
            }
        }
        if(inc != 0){res = _insertNode(res, inc);}
        return res;
    }
};
TEST(Q0002, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

} // namespace q0002
