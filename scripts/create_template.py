
import os, sys

def idx2str(idx, bits=2):
    return '%0*d'%(bits, idx)

def get_file_path(idx, dir_path='./'):
    return os.path.join(dir_path, 'sword_q' + idx + '.cpp')

def get_template(idx):
    head = """
/*
#剑指Offer# Q{}
""".format(idx)
    body = """

*/
#include "leetcode.h"
"""
    body2 = """
namespace sword_q{}""".format(idx)

    body3 = """
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

} """
    tail = """// namespace sword_q{}
""".format(idx)
    return head + body + body2 + body3 + tail

def main():
    start, end = 13, 50
    for i in range(start, end+1):
        idx = idx2str(i)
        file_path = get_file_path(idx)
        cont = get_template(idx)
        # print(idx)
        # print(file_path)
        # print(cont)
        with open(file_path, 'w') as wfid:
            wfid.write(cont)



if __name__ == '__main__':
    main()
