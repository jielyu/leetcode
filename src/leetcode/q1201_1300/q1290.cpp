/*
#面试刷题# 第0010期
#Leetcode# Q1290 将链表中二进制转换为十进制整数
难度：低
给定一个指向单链表的头指针head，链表中每个元素存储的值为0或者1，整个链表使用二进制表示一个数。
要求返回链表二进制所表示数字的十进制整数。
约束条件：
(a) 链表不为空
(b) 节点数不超过30
(c) 每个节点存储的数值为0或者1

例1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
例2:
Input: head = [0]
Output: 0
例3:
Input: head = [1]
Output: 1
例4:
Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
例5:
Input: head = [0,0]
Output: 0
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "leetcode.h"

namespace q1290{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<int> arr {1,0,1};
        ListNode * head = create_list(arr);
        int ret = slt.getDecimalValue(head);
        delete_list(head);
        if (5 != ret) {return false;}
    }

    {
        vector<int> arr {0};
        ListNode * head = create_list(arr);
        int ret = slt.getDecimalValue(head);
        delete_list(head);
        if (0 != ret) {return false;}
    }

    {
        vector<int> arr {1};
        ListNode * head = create_list(arr);
        int ret = slt.getDecimalValue(head);
        delete_list(head);
        if (1 != ret) {return false;}
    }

    {
        vector<int> arr {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
        ListNode * head = create_list(arr);
        int ret = slt.getDecimalValue(head);
        delete_list(head);
        if (18880 != ret) {return false;}
    }

    {
        vector<int> arr {0, 0};
        ListNode * head = create_list(arr);
        int ret = slt.getDecimalValue(head);
        delete_list(head);
        if (0 != ret) {return false;}
    }

    // succ
    return true;
}
 
class Solution {
public:
    // 0 ms, faster than 100.00%
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        while(head) {
            sum *= 2;
            sum += head->val;
            head = head->next;
        }
        return sum;
    }
};
TEST(Q1290, Solution) {EXPECT_EQ(q1290::run_testcases<q1290::Solution>(), true);}
};