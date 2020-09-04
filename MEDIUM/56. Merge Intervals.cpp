#include "leetcode.h"

class Solution {
public:
    static bool compareInterval(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return vector<vector<int>>();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compareInterval);
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};


int main() {
    vector<vector<int>> intervals = {
        {1,3},{2,6},{8,10},{15,18}
    };
    Solution sol;
    vector<vector<int>> res = sol.merge(intervals);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}