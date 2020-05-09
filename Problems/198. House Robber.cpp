#include "leetcode.h"


// DP:
// two options: 1. rob this house, 2. do not rob this house
// 1. i-2 profit + i profit
// 2. i-1 profit
// find which method can get more profit?
// use two variable to record the i-2 (prev2) and i-1 (prev1)


class Solution {
public:
    int rob(vector<int>& nums) {
        int profit;
        int prev1 = 0;
        int prev2 = 0;
        int temp;
        for(int i=0; i<nums.size(); i++) {
            temp = prev1;
            prev1 = max(prev2+nums[i], prev1);
            prev2 = temp;
        }
        return prev1;
    }
};

int main() {
    vector<int> nums = {1, 4, 5, 7, 1, 2};  // 4+7+2 = 13
    Solution s;
    cout << s.rob(nums) << endl;
}