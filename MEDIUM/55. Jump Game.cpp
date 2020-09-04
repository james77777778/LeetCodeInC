#include "leetcode.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        for(int i=0; i<nums.size() && i<=reach; i++) {
            reach = max(reach, i+nums[i]);
            if(reach>=nums.size()-1)
                return true;
        }
        return false;
    }
};


int main() {
    vector<int> nums = {3,2,1,0,4};
    Solution sol;
    cout << sol.canJump(nums) << endl;
}