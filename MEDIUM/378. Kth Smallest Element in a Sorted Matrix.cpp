# include "leetcode.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int midv, count;
        // binary search
        while(left < right) {
            midv = (left + right) / 2;
            count = 0;
            for(int i=0; i<n; i++) {
                vector<int>& row = matrix[i];
                count += std::upper_bound(row.begin(), row.end(), midv) - row.begin();
            }
            if(count < k)
                left = midv+1;
            else
                right = midv;
        }
        return left;
    }
};

int main() {
    /*
    matrix = [
    [ 1,  5,  9],
    [10, 11, 13],
    [12, 13, 15]
    ],
    */
    
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    matrix[0][0] = 1;
    matrix[0][1] = 5;
    matrix[0][2] = 9;
    matrix[1][0] = 10;
    matrix[1][1] = 11;
    matrix[1][2] = 13;
    matrix[2][0] = 12;
    matrix[2][1] = 13;
    matrix[2][2] = 15;

    Solution sol;
    cout << sol.kthSmallest(matrix, 8) << endl;
}