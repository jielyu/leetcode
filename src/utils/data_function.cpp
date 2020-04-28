#include "leetcode.h"

ListNode * create_list(vector<int> & arr) {
    int len = arr.size();
    if (len == 0) {
        return NULL;
    } 
    ListNode * head = new ListNode(arr[0]);
    ListNode * next = head;
    for (int i=1; i<len; ++i) {
        next->next = new ListNode(arr[i]);
        next = next->next;
    }
    return head;
}

void delete_list(ListNode * head) {
    ListNode * next = NULL;
    while(head) {
        next = head->next;
        delete head;
        head = next;
    }
}