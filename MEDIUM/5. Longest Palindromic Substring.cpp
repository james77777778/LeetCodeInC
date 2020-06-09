#include "leetcode.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string res = "";
        int l_idx, r_idx;
        if(s.size()<2)
            return s;
        if(s.size() == 2) {
            if(s[0] == s[1])
                return s;
            if(s[0] != s[1])
                return s.substr(0, 1);
        }
        for(int i=0; i<s.size()-1; i++) {
            l_idx = i;
            r_idx = i;
            // skip repeated char for r_idx
            while(r_idx < s.size()-1 && s[r_idx] == s[r_idx+1])
                r_idx ++;
            while(l_idx>=0 && r_idx<s.size() && s[l_idx] == s[r_idx]) {
                if((r_idx-l_idx+1) > maxLen) {
                    maxLen = r_idx-l_idx+1;
                    res = s.substr(l_idx, maxLen);
                }
                l_idx --;
                r_idx ++;
            }
        }
        return res;
    }
};


int main() {
    string s = "babad";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
}