#include "leetcode.h"


// use reverse integer to solve. easy one.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long reverse = 0;
        long temp = x;
        while (temp) {
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }
        if (reverse == x)
            return true;
        else
            return false;
    }
};

int main() {
    int x1 = 101;
    int x2 = -123;
    int x3 = 10;
    Solution s;
    cout << s.isPalindrome(x1) << endl;
    cout << s.isPalindrome(x2) << endl;
    cout << s.isPalindrome(x3) << endl;

    return 0;
}