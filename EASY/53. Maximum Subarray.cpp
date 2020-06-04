#include "leetcode.h"


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
    int divide_and_conquer(vector<int> &nums, int left, int right) {
        // conquer
        if(left == right)
            return nums[left];
        
        // divide
        int mid = (left + right) / 2;
        int left_max = divide_and_conquer(nums, left, mid);
        int right_max = divide_and_conquer(nums, mid+1, right);
        
        // merge
        int max_l = INT_MIN;
        int max_r = INT_MIN;
        for(int i=mid, sum=0; i>left-1; i--) {
            sum += nums[i];
            if(sum > max_l)
                max_l = sum;
        }
        for(int i=mid+1, sum=0; i<right+1; i++) {
            sum += nums[i];
            if(sum > max_r)
                max_r = sum;
        }
        int cross_max = max_l + max_r;
        int res_max = max(max(left_max, right_max), cross_max);
        return res_max;
    }
    int maxSubArray_DC(vector<int>& nums) {
        int ans = divide_and_conquer(nums, 0, nums.size()-1);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;  // 6
    cout << s.maxSubArray_DC(nums) << endl;  // 6
    return 0;
}