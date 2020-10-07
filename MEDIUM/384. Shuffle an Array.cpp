#include "leetcode.h"

class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    // Fisher Yates algorithm
    vector<int> shuffle() {
        vector<int> res(nums);
        int idx;
        for(int i=nums.size()-1; i>=0 ; i--) {
            idx = rand() % (i+1);
            swap(res[i], res[idx]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */