#include "leetcode.h"

class Solution {
public:
    void sortColorsTwopass(vector<int>& nums) {
        vector<int> count(3);
        for(int i=0; i<nums.size(); i++)
            count[nums[i]]++;
        int idx = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<count[i]; j++) {
                nums[idx] = i;
                idx++;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1)
                mid++;
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


int main() {
    vector<int> nums = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(nums);
    for(int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}