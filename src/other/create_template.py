
import os, sys

def idx2str(idx, bits=4):
    return '%0*d'%(bits, idx)

def get_file_path(idx, dir_path='./', prefix='q', suffix='cpp'):
    return os.path.join(dir_path, prefix + idx + '.' + suffix)

def get_template(idx):
    head = """
/*
#LeetCode# Q{}
""".format(idx)
    body = """

*/
#include "leetcode.h"
"""
    body2 = """
namespace q{}""".format(idx)

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
    tail = """// namespace q{}
""".format(idx)
    return head + body + body2 + body3 + tail

def main():
    exclude_list = [1, 2, 3, 5, 102, 48, 306, 779, 1044, 1078]

    start, end = 780, 1252
    for i in range(start, end+1):
        if i in exclude_list:
            continue

        # 创建目录
        min_i, max_i = int((i-1)/100) * 100 + 1, (int((i-1)/100)+1) * 100 
        dirname = 'q' + idx2str(min_i, 4) + '_' + idx2str(max_i, 4)
        if not os.path.isdir(dirname):
            os.makedirs(dirname)
        
        # 获取文件路径
        idx = idx2str(i)
        file_path = get_file_path(idx, dir_path=dirname)

        # 获取模版文件的内容
        cont = get_template(idx)

        # 创建文件，并写入内容
        with open(file_path, 'w') as wfid:
            wfid.write(cont)



if __name__ == '__main__':
    main()
