/*
#剑指Offer# Q07 用两个栈实现一个队列
完成在队列的尾部插入节点和队列头部删除节点两个操作
*/
#include "leetcode.h"

namespace sword_q07
{

template<typename T>
bool run_testcases() {
    T slt;

    slt.push(1);
    slt.push(2);
    CHECK_RET(1 == slt.pop());
    slt.push(3);
    slt.push(4);
    CHECK(2 == slt.pop());
    CHECK(3 == slt.pop());
    CHECK(4 == slt.pop());

    return true;
}

class Solution {
private:
    stack<int> _stack1, _stack2;
public:
    void push(int val) {
        _stack1.push(val);
    }
    int pop(){
        if (_stack2.size() == 0) {
            while (_stack1.size() > 0) {
                _stack2.push(_stack1.top());
                _stack1.pop();
            }
        }
        if (_stack2.size() == 0) {throw "empty queue";}
        int val = _stack2.top();
        _stack2.pop();
        return val;
    }
};
TEST(SwordQ07, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q07