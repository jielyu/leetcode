
/*
#LeetCode# Q0065 有效数字
难度：高
验证一个给定的字符串是否可以被解释为十进制数。

一些例子。
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3 " => true
"1e" => false
"e3" => false
"6e-1" => true
"99e2.5" => false
"53.5e93" => true
" -6 " => false
"-+3" => false
"95a54e53" => false

注意：希望问题陈述是模糊不清的。你应该在实施前收集所有的需求，然后再实施一个。但是，以下是一个有效的十进制数字中可以出现的字符列表。

数字0-9
指数 - "e"
正/负号--"+"/"-"-"
小数点 - "."
当然，在输入中，这些字符的上下文也很重要。

更新（2015-02-10）。
C++函数的签名已经更新了。如果你仍然看到你的函数签名接受了一个 const char *参数，请点击重新加载按钮重置你的代码定义。


*/
#include "leetcode.h"

namespace q0065
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
public:
    void func();
};

} // namespace q0065
