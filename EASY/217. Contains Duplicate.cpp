#include "leetcode.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq_table;
        for(int i: nums) {
            freq_table[i] ++;
            if(freq_table[i] > 1)
                return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 1};
    Solution s;
    cout << s.containsDuplicate(nums1) << endl;
    cout << s.containsDuplicate(nums2) << endl;
}