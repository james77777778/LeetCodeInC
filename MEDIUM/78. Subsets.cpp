#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        helper(nums, sub, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<int> sub, int pos) {
        res.push_back(sub);
        for(int i=pos; i<nums.size(); i++) {
            sub.push_back(nums[i]);
            helper(nums, sub, i+1);
            sub.pop_back();
        }
    }
};


int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.subsets(nums);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}