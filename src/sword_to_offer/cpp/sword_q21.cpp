
/*
#剑指Offer# Q21 包含min函数的栈
实现一个栈的数据结构，其中包含一个能够获取最小元素的min函数，要求在该栈中调用min，push，pop都是O(1)时间复杂度。

*/
#include "leetcode.h"

namespace sword_q21
{

template<typename T>
bool run_testcases() {
    T slt;

    slt.push(1);
    slt.push(2);
    CHECK_RET(1==slt.min());
    slt.pop();
    slt.pop();
    slt.push(4);
    CHECK_RET(4==slt.min());

    return true;
}

class Solution {
private:
    stack<int> _data, _min_data;
public:
    int min() {
        if (_data.size()>0 && _min_data.size()>0) {
            return _min_data.top();
        }
        return -1;
    }

    void push(int val) {
        _data.push(val);
        if (_min_data.size()==0 || val < _min_data.top()) {
            _min_data.push(val);
        } else {
            _min_data.push(_min_data.top());
        }
    }

    int pop() {
        if (_data.size() > 0 && _min_data.size() > 0) {
            int ret = _data.top();
            _data.pop();
            _min_data.pop();
            return ret;
        }
        return -1;
    }
};
TEST(SwordQ21, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q21
