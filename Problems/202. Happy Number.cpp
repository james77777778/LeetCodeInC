#include "leetcode.h"

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> encounter;
        int sum;
        while(n != 1) {
            if(encounter[n] == 0)
                encounter[n] ++;
            else
                return false;
            sum = 0;
            while(n) {
                sum += pow((n%10), 2);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    cout << s.isHappy(2) << endl;
}