#include "leetcode.h"

class Solution {
public:
    vector<int> topKFrequentSlow(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] ++;
        vector<vector<int>> v;
        for(auto& i: m) {
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), [](vector<int> a, vector<int> b){return a[1]>b[1];});
        vector<int> res;
        for(int i=0; i<k ;i++) {
            res.push_back(v[i][0]);
        }
        return res;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] ++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto& iter: m) {
            bucket[iter.second].push_back(iter.first);
        }
        vector<int> res;
        for(int i=bucket.size()-1; i>=0 && res.size()<k; i--) {
            for(int item: bucket[i]) {
                res.push_back(item);
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 1;
    Solution sol;
    vector<int> res = sol.topKFrequent(nums, k);
    for(int i: res)
        cout << i << " ";
    cout << endl;
}