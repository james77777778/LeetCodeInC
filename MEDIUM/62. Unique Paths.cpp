#include "leetcode.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        double res=1;
        int sum = m+n-2;
        int big, small;
        if(m>n) {
            big = m-1;
            small = n-1;
        }
        else {
            big = n-1;
            small = m-1;
        }
        for(int i=big+1, j=1; i<=sum; i++, j++) {
            res *= i;
            res /= j;
        }
        return int(res);
    }
};


int main() {
    int m=3, n=2;
    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
}