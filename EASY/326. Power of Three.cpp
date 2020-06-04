#include "leetcode.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n > 1) {
            while(n % 3 == 0)
                n /= 3;
        }
        return (n == 1);
    }
};


int main() {
    Solution s;
    cout << "9: " << s.isPowerOfThree(9) << endl;
    cout << "45: " << s.isPowerOfThree(45) << endl;
}