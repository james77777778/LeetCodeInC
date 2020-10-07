#include "leetcode.h"

class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size()-1);
    }
    int helper(string& s, int k, int l, int r) {
        if(l > r)
            return 0;
        // counting
        vector<int> cnt(26, 0);
        for(int i=l; i<=r; i++)
            cnt[s[i]-'a']++;
        // check whole string
        bool pass = true;
        for(int i=0; i<26 && pass; i++) {
            if(cnt[i] && cnt[i] < k)
                pass = false;
        }
        if(pass)
            return r-l+1;
        // divide string by occurance > 0 and < k
        int i = l, ans = 0;
        for(int j=l; j<=r; j++) {
            if(cnt[s[j]-'a'] && cnt[s[j]-'a'] < k) {
                ans = max(ans, helper(s, k, i, j-1));
                i = j+1;
            }
        }
        return max(ans, helper(s, k, i, r));
    }
};

int main() {
    string s = "ababbc";
    int k = 2;
    Solution sol;
    cout << sol.longestSubstring(s, k) << endl;
}