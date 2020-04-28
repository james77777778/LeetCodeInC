#include "leetcode.h"


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = 0;
        for (int i=0; i<s.length()-1; i++) {
            int cur = roman_table[s[i]];
            int next = roman_table[s[i+1]];
            if (cur < next)
                ans -= cur;
            else
                ans += cur;
        }
        ans += roman_table[s.back()];
        return ans;
    }
};

int main() {
    string s1 = "MCMXCIV";  // 1994
    Solution s;
    cout << s.romanToInt(s1) << endl;
    return 0;
}