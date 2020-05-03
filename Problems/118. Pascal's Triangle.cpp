#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        for(int r=0; r<numRows; r++) {
            pascal[r].resize(r+1);
            
            for(int c=0; c<r+1; c++) {
                if(c==0 || c==r)
                    pascal[r][c] = 1;
                else
                    pascal[r][c] = pascal[r-1][c-1]+pascal[r-1][c];
            }
        }
        return pascal;
    }
};

int main() {
    int numRows = 5;
    Solution s;
    vector<vector<int>> pascal = s.generate(numRows);

    for(vector<int> row: pascal) {
        for(int item: row)
            cout<< item << " ";
        cout << endl;
    }
}