#include "leetcode.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> cnt;
        for(int i=0; i<nums1.size(); i++)
            cnt[nums1[i]] ++;
        vector<int> res;
        for(int i=0; i<nums2.size(); i++) {
            if(cnt.find(nums2[i]) != cnt.end() && cnt[nums2[i]] > 0) {
                res.emplace_back(nums2[i]);
                cnt[nums2[i]] --;
            }            
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2, 3};
    Solution sol;
    vector<int> res = sol.intersect(nums1, nums2);
    for(int num: res)
        cout << num << " ";
    cout << endl;
}