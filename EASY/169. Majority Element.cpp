#include "leetcode.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums) {
            if(++freq[n] > nums.size()/2)
                return n;
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {3, 3, 3, 1, 2, 3, 4};
    Solution s;
    cout << s.majorityElement(nums) << endl;
}