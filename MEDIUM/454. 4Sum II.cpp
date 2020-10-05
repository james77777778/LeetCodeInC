#include "leetcode.h"

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ABSum;
        int res = 0;
        for(int i: A)
            for(int j: B)
                ABSum[i+j]++;
        for(int i: C)
            for(int j: D)
                res += ABSum[-i-j];
        return res;
    }
};


int main() {
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    Solution sol;
    cout << sol.fourSumCount(A, B, C, D) << endl;
}