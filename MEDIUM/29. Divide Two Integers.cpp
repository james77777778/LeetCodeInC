#include "leetcode.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        // check overflow
        if(divisor == INT_MIN)
            return dividend == INT_MIN? 1: 0;
        if(dividend == INT_MIN) {
            if(divisor == 1)
                return INT_MIN;
            if(divisor == -1)
                return INT_MAX;
            dividend += abs(divisor);
            quotient += 1;
        }
        //
        bool negative = (dividend>0) != (divisor>0);
        int A = abs(dividend);
        int B = abs(divisor);
        while(A-B >= 0) {
            int B_ = B;
            int quotient_ = 1;
            while(A >= (B_ << 1) && (B_ << 1) > 0) {
                B_ <<= 1;
                quotient_ <<= 1;
            }
            A -= B_;
            quotient += quotient_;
        }
        return negative? -quotient: quotient;
    }
};


int main() {
    Solution sol;
    cout << sol.divide(100, 3) << endl;
}