#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }
    void helper(vector<int>& nums, int pos) {
        if(pos == nums.size()-1)
            res.push_back(nums);
        else {
            for(int i=pos; i<nums.size(); i++) {
                swap(nums[pos], nums[i]);
                helper(nums, pos+1);
                swap(nums[pos], nums[i]);
            }
        }
    }
};


int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.permute(nums);
    for(vector<int> item: res) {
        for(int v: item) {
            cout << v << " ";
        }
        cout << endl;
    }
}