#include "leetcode.h"

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int mid;
        while(low <= high) {
            mid = (high+low)/2;
            if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int left = lower_bound(nums, target);
        int right = lower_bound(nums, target+1)-1;
        if(left < nums.size() && nums[left] == target)
            return {left, right};
        else
            return {-1, -1};
    }
};


int main() {
    vector<int> nums = {5,7,7,8,8,10};
    Solution sol;
    vector<int> res = sol.searchRange(nums, 8);
    for(int i: res)
        cout << i << " ";
    cout << endl;
}