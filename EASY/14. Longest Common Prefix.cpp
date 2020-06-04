#include "leetcode.h"


// common prefix: from head to tail

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() == 0)
            return prefix;
        for (int i_prefix=0; i_prefix<strs[0].length(); i_prefix++) {
            int i_strs = 1;
            for (; i_strs<strs.size(); i_strs++) {
                if (strs[0][i_prefix] != strs[i_strs][i_prefix])
                    return prefix;
            }
            prefix += strs[0][i_prefix];
        }
        return prefix;
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}