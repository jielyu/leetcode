/*
#面试刷题# 第66期
#Leetcode# Q1381 使用递增操作设计堆栈
难度：中
设计一个支持以下操作的堆栈。
实现CustomStack类：
    CustomStack（int maxSize）使用maxSize初始化对象，
        该maxSize是堆栈中元素的最大数量；如果堆栈达到maxSize，则不执行任何操作。
    void push（int x）如果堆栈尚未达到maxSize，则将x添加到堆栈的顶部。
    int pop（）弹出并返回堆栈的顶部；如果堆栈为空，则返回-1。
    void inc（int k，int val）按val递增堆栈的底部k个元素。
        如果堆栈中的元素少于k，则只需增加堆栈中的所有元素。
约束条件：
(a) 1 <= maxSize <= 1000
(b) 1 <= x <= 1000
(c) 1 <= k <= 1000
(d) 0 <= val <= 100
(e) 每种增量方法最多可调用1000次，分别推入和弹出

例1:
Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
Explanation
CustomStack customStack = new CustomStack(3); // Stack is Empty []
customStack.push(1);                          // stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.push(3);                          // stack becomes [1, 2, 3]
customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
customStack.increment(5, 100);                // stack becomes [101, 102, 103]
customStack.increment(2, 100);                // stack becomes [201, 202, 103]
customStack.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
customStack.pop();                            // return 202 --> Return top of the stack 102, stack becomes [201]
customStack.pop();                            // return 201 --> Return top of the stack 101, stack becomes []
customStack.pop();                            // return -1 --> Stack is empty return -1.
*/
#include "leetcode.h"


namespace q1381{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

// Runtime: 48 ms, faster than 23.73%
// Memory Usage: 19.4 MB, less than 100.00%
class CustomStack {
private:
    vector<int> _stack;
    const int _max_size;
    // valid range [0, _top_idx)
    int _top_idx;
    
public:
    CustomStack(int maxSize): _max_size(maxSize) {
        this->_stack.clear();
        this->_stack.resize(maxSize);
        this->_top_idx = 0;
    }
    
    void push(int x) {
        if (this->_top_idx >= this->_max_size) {
            return;
        }
        this->_stack[this->_top_idx] = x;
        ++this->_top_idx;
    }
    
    int pop() {
        if (this->_top_idx > 0) {
            --this->_top_idx;
            return this->_stack[this->_top_idx];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int high_idx = this->_top_idx >= k ? k : this->_top_idx;
        for (--high_idx; high_idx >= 0; --high_idx) {
            this->_stack[high_idx] += val;
        }
    }
};



/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

};
