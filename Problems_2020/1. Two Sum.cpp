#include "leetcode.h"


// use unordered_map to store the information <value, index>
// if there is no suitable value found in map, store it

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_map;
        
        for(int i=0; i<nums.size(); i++) {
            int find_value = target - nums[i];
            auto iter = value_map.find(find_value);
            
            if(iter != value_map.end()) {
                return {i, iter->second};    
            }
            
            value_map[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> ans = s.twoSum(nums, target);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}