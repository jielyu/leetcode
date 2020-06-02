#include <iostream>
using namespace std;

/*
给定两个只有小写字母abc组成的字符串，block和target，对block可做如下操作
(1) 任意交换两个字母的位置
(2) 把其中一种字母全部替换成另外一种字母，比如aaccb替换a得到bbccb
求最少操作多少次，block和target一样
*/

class Solution {
private:
    void _replace(string & s, char source, char target) {
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (source == s[i]) {s[i] = target;} 
        }
    }

public:
    int stringReplace(string & block, string & target) {
        int len = block.size(), ret = 0;
        if (block == target) {return 0;}
        const int MAX_NUM = 3;
        // 统计直方图
        int b_stat[MAX_NUM] = {0}, t_stat[MAX_NUM] = {0};
        for (int i = 0; i < len; ++i) {
            if (block[i] < 'a' || block[i] > 'c' 
                    || target[i] < 'a' || target[i] > 'c') {return -1;}
            ++b_stat[block[i] - 'a'];
            ++t_stat[target[i] - 'a'];
        }
        // 替换字符：target中没有的，block中存在就进行替换，目标是
        int diff_stat[MAX_NUM] = {0};
        for (int i = 0; i < MAX_NUM; ++i) {
            //cout << (char)('a' + i) << ":" << b_stat[i] << "," << t_stat[i] << endl;
            // 只有target中没有的字符却在block中存在的，才需要替换
            if (t_stat[i] == 0 && b_stat[i] != 0) {
                for (int j = 0; j < MAX_NUM; ++j) {
                    if (i == j) {continue;}
                    // 替换目标必须满足替换后不超过tagret中该字符数量
                    if (t_stat[j] >= b_stat[j] + b_stat[i]) {
                        cout << "replace: " << i << "->" << j << endl;
                        // 将block中的i全都换成j所指向的字符
                        _replace(block, (char)('a' + i), (char)('a'+j));
                        b_stat[j] += b_stat[i];
                        b_stat[i] = 0;
                        // 操作计数
                        ++ret;
                        break;
                    }
                }
            }
        }
        // 检查：替换之后仍不相同，则无解决方案
        for (int i = 0; i < MAX_NUM; ++i) {if (b_stat[i] != t_stat[i]){return -1;}}
        if (block == target) {return ret;}
        // 移动
        for (int i = 0; i < len; ++i) {
            if (block[i] != target[i]) {
                for (int j = i + 1; j < len; ++j) {
                    if (block[j] != target[j] && block[j] == target[i]) {
                        cout << "swap: " << i << "<->" << j << endl;
                        // 交换block中的i和j
                        char tmp = block[i];
                        block[i] = block[j];
                        block[j] = tmp;
                        // 操作计数
                        ++ret;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};

bool testcase(string block, string target, int ret) {
    Solution slt;
    int cnt = slt.stringReplace(block, target);
    cout << block << "->" << target 
         << ": pred=" << cnt << ", truth=" << ret 
         << ", correct=" << (cnt == ret)  << endl;
    return cnt == ret;
}

int main() {
    // 一次替换可以完成的例子
    testcase("aaccb", "bbccb", 1);
    // 两次替换可以完成
    testcase("aaccb", "ccccc", 2);
    // 一次替换，一次交换
    testcase("aaccb", "bbbcc", 2);
    // 一次替换，两次交换
    testcase("aacbb", "bcbcc", 3);
    // 无法完成任务的例子
    testcase("aacbb", "bcbca", -1);

    return 0;
}