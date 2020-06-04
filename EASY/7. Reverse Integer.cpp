#include "leetcode.h"


// main idea: store the intermediate answer temp = ans*10+x%10
// needs a lot of overflow checkings (INT_MIN / negative / INT_MAX)

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);
        int ans = 0;
        while (x) {
            if (ans > INT_MAX /10 || ans*10 > INT_MAX - x%10)
                return 0;
            int temp = ans*10 + x%10;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};

int main() {
    int x1 = -12345;
    int x2 = 12345;
    Solution s;
    cout << s.reverse(x1) << endl;
    cout << s.reverse(x2) << endl;
    return 0;
}