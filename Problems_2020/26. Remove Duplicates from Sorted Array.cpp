#include "leetcode.h"


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int length = 0;
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] != nums[i+1]) {
                nums[length+1] = nums[i+1];
                length ++;
            }
        }
        return length+1;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 2, 2, 3, 4, 5};
    Solution s;
    int len = s.removeDuplicates(nums);
    for (int i=0; i<len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}