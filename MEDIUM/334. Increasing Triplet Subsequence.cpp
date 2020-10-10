#include "leetcode.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX;
        int mid = INT_MAX;
        // record min candidate and mid candidate
        // This solution is correct for input [2, 6, 1, 8].
        // It doesn't matter that c1 is set to the incorrect number,
        // you are comparing the 8 to c2. It is greater so you return true.
        // And c2 is only set because you found a c1 before it which is smaller.
        // It is not possible for c2 to be set to a certain number and
        // not have a number before it be smaller.
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < min)
                min = nums[i];
            else if(nums[i] < mid && nums[i] > min)
                mid = nums[i];
            else if(nums[i] > mid)
                return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution sol;
    cout << sol.increasingTriplet(nums) << endl;
}