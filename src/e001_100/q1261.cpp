/*
#面试刷题# 第0014期
#Leetcode# Q1261 在污染的二叉树中查找元素
难度：中
给定一个满足下列规则的二叉树：
1. root.val == 0
2. 如果 treeNode.val == x 并且 treeNode.left != null, 则 treeNode.left.val == 2 * x + 1
3. 如果 treeNode.val == x 并且 treeNode.right != null, 则 treeNode.right.val == 2 * x + 2
现在二叉树被污染了，这意味着所有treeNode.val都被修改成了-1.
你需要首先修复二叉树，然后实现FindElements类。该类包含两个需要实现的成员函数：
FindElements(TreeNode* root)，你需要在这个构造函数中修复已被污染的二叉树
bool find(int target) 在target存在的情况下，返回true；否则返回false
约束条件：
(a) TreeNode.val == -1
(b) 树的深度小于等于 20
(c) 树的节点数量范围 [1, 10^4]
(d) find函数被调用次数范围 [1, 10^4]
(e) 0 <= target <= 10^6

例1:
Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 
例2:
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
例3:
Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
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

// Runtime: 40 ms, faster than 76.66% 
// Memory Usage: 21 MB, less than 100.00% 
class FindElements {
private:
    TreeNode * _root;
    void _recover(TreeNode * root) {
        if (!root) {return;}
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            _recover(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            _recover(root->right);
        }
    }
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        _recover(root);
        this->_root = root;
    }
    
    bool find(int target) {
        if (!target) {
            return true;
        }
        // construct path flags
        vector<int> is_left;
        while(target) {
            int r = target % 2;
            is_left.push_back(r);
            //cout << r << endl;
            target -= (r > 0 ? r : 2);
            target /= 2;
        }
        // traversing the tree
        TreeNode * root = this->_root;
        for (auto iter=is_left.rbegin(); iter != is_left.rend(); ++iter) {
            if (0 == (*iter)) {
                root = root->right;
            } else {
                root = root->left;
            }
            if (!root) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */