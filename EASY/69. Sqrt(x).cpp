#include "leetcode.h"


// Newton's Iterative Method
// sqrt(n) is to find the solution of f(x) = x^2 - n = 0
// f(x_{n+1}) = f(x_n) + f'(x_n)*(x_{n+1} - x_n)
// => 0 = f(x_n) + f'(x_n)*(x_{n+1} - x_n)
// => x_{n+1} = x_n - f(x_n) / f'(x_n) = x_n - ((x_n)^2 - n)/(2*x_n)
// => x_{n+1} = (x_n + n / x_n) / 2

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        double ans = x/2;  // init guess
        double delta = 0.0001;  // precision
        while(fabs(pow(ans, 2) - x) > delta) {
            ans = (ans + x/ans)/2;  // x_{n+1} = (x_n + n / x_n) / 2
        }
        return int(ans);
    }
};

int main() {
    int x = 7;
    Solution s;
    cout << s.mySqrt(x) << endl;
    return 0;
}