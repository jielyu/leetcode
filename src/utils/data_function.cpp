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

void get_preorder(TreeNode * root, vector<int> & preorder) {
    if (!root) {return;}
    preorder.push_back(root->val);
    get_preorder(root->left, preorder);
    get_preorder(root->right, preorder);
}

void get_inorder(TreeNode * root, vector<int> & inorder) {
    if (!root) {return;}
    get_inorder(root->left, inorder);
    inorder.push_back(root->val);
    get_inorder(root->right, inorder);
}

void delete_tree(TreeNode * root) {
    if (!root) {return;}
    if (root->left) {delete_tree(root->left);}
    if (root->right) {delete_tree(root->right);}
    delete root;
}
