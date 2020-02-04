#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // record states for remaider = 0,1,2 situations
        vector<int> remainds{int(-4e8), int(-4e8), int(-4e8)};
        int mid = 0;
        for (auto & v : nums) {
            if (v % 3 == 0) { // can only initialize remainds[0]
                remainds[0] = max(remainds[0] + v, v);
                remainds[1] = remainds[1] > 0 ? remainds[1] + v : remainds[1];
                remainds[2] = remainds[2] > 0 ? remainds[2] + v : remainds[2];
            } else if (v % 3 == 1) { // can only initialize remainds[1]
                mid = remainds[0];
                remainds[0] = remainds[2] > 0 ? max(remainds[0], remainds[2] + v) : remainds[0];
                remainds[2] = remainds[1] > 0 ? max(remainds[2], remainds[1] + v) : remainds[2];
                remainds[1] = max(remainds[1], max(mid + v, v));
            } else { // can only initialize remainds[2]
                mid = remainds[0];
                remainds[0] = remainds[1] > 0 ? max(remainds[0], remainds[1] + v) : remainds[0];
                remainds[1] = remainds[2] > 0 ? max(remainds[1], remainds[2] + v) : remainds[1];
                remainds[2] = max(remainds[2], max(mid + v, v));  
            }
            //std::cout << v << "," << remainds[0] << "," 
            //          << remainds[1] << "," << remainds[2] <<std::endl;
        }
        return max(0, remainds[0]);
    }
};

int main() {
    vector<int> nums{1,2,3,4,4};
    Solution slt;
    cout << slt.maxSumDivThree(nums) << endl;
    return 0;
}