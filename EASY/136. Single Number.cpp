#include "leetcode.h"

// Use XOR gate
// binary: 101 ^ 111 = 010 ; 0011 ^ 1100 = 0000
// When the same numbers encouter, it will become 0 bits.
// Only the single number will perserve. 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int n: nums)
            ans ^= n;
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution s;
    cout << s.singleNumber(nums) << endl;
}