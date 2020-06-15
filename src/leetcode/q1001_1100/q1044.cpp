/*
1044. Longest Duplicate Substring

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

Example 1:
Input: "banana"
Output: "ana"

Example 2:
Input: "abcd"
Output: ""

Note:
2 <= S.length <= 10^5
S consists of lowercase English letters.

*/

#include "leetcode.h"

namespace q1044{

template<typename T>
bool run_testcases() {
    T slt;
    CHECK_RET(slt.longestDupSubstring("banana") == "ana");
    CHECK_RET(slt.longestDupSubstring("abcd") == "");
    return true;
}
class Solution {
public:

    //Status: Time Limit Exceeded
    string longestDupSubstring(string S) {
        int dup_idx = 0, dup_len = 0, tmp_len = 0, len = S.length();
        auto * data =  S.data();
        for (int i = 0; i < len - 1; ++i) {
            tmp_len = 0;
            for (int j = i + 1; j < len; ++j) {
                //std::cout << data[i]<<"," << data[j]<<","<<data[i+tmp_len]<<","<<tmp_len << std::endl;
                if (data[i + tmp_len] == data[j]) {
                    ++tmp_len;
                } else {
                    if (dup_len < tmp_len) {
                        dup_idx = i;
                        dup_len = tmp_len;
                    }
                    tmp_len = 0;
                }
            }
            if (dup_len < tmp_len) {
                dup_idx = i;
                dup_len = tmp_len;
            }
        }
        //std::cout << "idx=" << dup_idx << ", len=" << dup_len << std::endl;
        return S.substr(dup_idx, dup_len);
    }
};
TEST(Q1044, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

};
