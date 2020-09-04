#include "leetcode.h"

// use first col and first row to store the information
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstCol = false, firstRow = false;
        // check first col
        for(int i=0; i<matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }
        // check first row
        for(int i=0; i<matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }
        // check the points from second
        for(int i=1; i<matrix.size(); i++) {
            for(int j=1; j<matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // process the points from second
        for(int i=1; i<matrix.size(); i++) {
            for(int j=1; j<matrix[i].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstCol) {
            for(int i=0; i<matrix.size(); i++)
                matrix[i][0] = 0;
        }
        if(firstRow) {
            for(int i=0; i<matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    Solution sol;
    sol.setZeroes(matrix);
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}