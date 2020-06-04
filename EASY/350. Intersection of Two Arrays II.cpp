#include "leetcode.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num_table;
        vector<int> result;
        for(int i: nums1)
            num_table[i] ++;
        for(int j: nums2) {
            if(num_table.find(j) != num_table.end() && num_table[j]-- > 0)
                result.push_back(j);
        }
        return result;
    }
};


int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution s;
    vector<int> res = s.intersect(nums1, nums2);
    for(int i: res)
        cout << i << " ";
    cout << endl;
}