#include "leetcode.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur_idx = 0;
        for(int i=cur_idx; i<nums.size(); i++) {
            if(nums[i] != 0) {
                nums[cur_idx] = nums[i];
                cur_idx++;
            }
        }
        for(int j=cur_idx; j<nums.size(); j++)
            nums[j] = 0;
    }
};


int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums);
    for(int i: nums)
        cout << i << " ";
    cout << endl;
}