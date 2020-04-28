#include "leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int sum = 0;
        for(int i=digits.size()-1; i>=0; i--) {
            sum = digits[i] + carry;
            if(sum < 10){
                carry = 0;
                digits[i] = sum;
                return digits;
            }
            else {
                carry = 1;
                digits[i] = sum - 10;
            }
        }
        if(carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main() {
    vector<int> digits = {1, 8, 9, 9};
    Solution s;
    vector<int> plus_one = s.plusOne(digits);
    for(int i=0; i<plus_one.size(); i++) {
        cout << plus_one[i] << " ";
    }
    cout << endl;
    return 0;
}