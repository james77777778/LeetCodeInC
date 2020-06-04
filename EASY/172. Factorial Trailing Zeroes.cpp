#include "leetcode.h"


// 1. find how many 5 in n
// 2. find how many 5x5 in n
// 3. find how many 5x5x5 in n
// ......
// ex: 100! = (20 of 5) + (4 of 5x5) = 24 trailing zeros


class Solution {
public:
    int trailingZeroes(int n) {
        int n_five = 0;
        for(long i=5; n/i>0; i*=5) {
            n_five += (n/i);
        }
        return n_five;
    }
};

int main() {
    Solution s;
    cout << s.trailingZeroes(100) << endl;
}