#include "leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        vector<int> dict(256, -1);
        int start_idx = -1;
        for(int i=0; i<s.size(); i++) {
            if(dict[s[i]] > start_idx)
                start_idx = dict[s[i]];
            dict[s[i]] = i;
            max_len = max(max_len, i-start_idx);
        }
        return max_len;
    }
};


int main() {
    string s = "abcdabcabcdefg";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
}