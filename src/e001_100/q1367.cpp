/*
#面试刷题# 第0081期
#Leetcode# Q1367 二叉树中的链表
难度：中
给定二叉树root和以head为第一个节点的链表。
如果链表中从头开始的所有元素都与二进制树中连接的某些向下路径相对应，
则返回True，否则返回False。
在这种情况下，向下路径是指从某个节点开始并向下移动的路径。
约束条件：
(a) 对于链表和二进制树中的每个节点，1 <= node.val <= 100。
(b) 给定的链表将包含1到100个节点。
(c) 给定的二叉树将包含1到2500个节点。

示例1:
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  

示例2:
Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true

示例3:
Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Runtime: 40 ms, faster than 54.74% 
// Memory Usage: 22.3 MB, less than 100.00%
class Solution {
private:
    bool is_match(ListNode* head, TreeNode* root) {
        if (!head) {return true;}
        if (!root) {return false;} 
        if (head->val != root->val) { return false;}
        auto is_left = is_match(head->next, root->left);
        auto is_right = is_match(head->next, root->right);
        return is_left || is_right;
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) {return false;}
        if (is_match(head, root)) {
            return true;
        } else {
            auto is_left = isSubPath(head, root->left);
            if (is_left) { return true;}
            auto is_right = isSubPath(head, root->right);
            if (is_right) { return true;}
        }
        return false;
    }
};