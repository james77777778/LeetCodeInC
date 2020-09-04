#include "leetcode.h"

// https://leetcode.com/problems/powx-n/discuss/659996/Binary-exponential-indepth-explanation
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool negative = n>0? 0: 1;
        n = abs(n);
        while(n>0) {
            if(n & 1 == 1)
                res *= x;
            x *= x;
            n >>= 1;
        }
        return negative? 1/res: res;
    }
};


int main() {
    double x = 3;
    int n = 3;
    Solution sol;
    cout << sol.myPow(x, n) << endl;
}