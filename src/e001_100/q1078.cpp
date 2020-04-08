#include "leetcode.h"

namespace q1078{
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // construct pattern string
        string key = first + " " + second + " ";
        int len = (int)(text.size());

        vector<string> res;
        int start = 0;
        const char * p_text = text.data();
        while(start < len - 1) {
            // get sub string
            string sub = text.substr(start, len-start);
            // find key pattern in substring
            int pos = sub.find(key);
            cout << "sub=" << sub << ", pos=" << pos << endl;
            if ( pos == string::npos) {
                break;
            }
            // get the third word
            int start_res_pos = start + pos + key.size();
            for (int i=start_res_pos; i<=len; ++i) {
                if (i == len || p_text[i] == ' ') {
                    string sub_res = text.substr(start_res_pos, i - start_res_pos);
                    res.push_back(sub_res);
                    if (sub_res == first) {
                        start += key.size() + pos;
                    } else {
                        start = i + 1;
                    }
                    break;
                }
            }
        }
        return res;
    }
};

};
