#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        
        int target, front, back, sum;
        for(int i=0; i<nums.size();i++) {
            target = -nums[i];
            front = i+1;
            back = nums.size()-1;
            while(front < back) {
                sum = nums[front] + nums[back];
                if(sum < target)
                    front ++;
                else if(sum > target)
                    back --;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    // skip duplicate number
                    while(front < back && nums[front] == triplet[1])
                        front ++;
                    while(front < back && nums[back] == triplet[2])
                        back --;
                }
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};


int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}