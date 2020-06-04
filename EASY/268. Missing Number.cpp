#include "leetcode.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            count += i - nums[i];
        }
        count += nums.size();  // need to add the final number
        return count;
    }
    int missingNumber_XOR(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            count ^= nums[i];
            count ^= i;
        }
        count ^= nums.size();  // need to XOR the final number
        return count;
    }
    int missingNumber_cal(vector<int>& nums) {
        int sum = (nums.size()*(nums.size()+1)/2);
        for(int i: nums) {
            sum -= i;
        }
        return sum;
    }
};


int main() {
    vector<int> nums = {3, 0, 1};
    Solution s;
    cout << s.missingNumber(nums) << " " << s.missingNumber_XOR(nums) << " " << s.missingNumber_cal(nums) << endl;
}