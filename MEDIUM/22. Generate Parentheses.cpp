#include "leetcode.h"

class Solution {
public:
    vector<string> res;
    void helper(string s, int l_paren, int r_paren) {
        if(l_paren == 0 && r_paren == 0)
            res.push_back(s);
        if(l_paren > 0)
            helper(s+"(", l_paren-1, r_paren+1);
        if(r_paren > 0)
            helper(s+")", l_paren, r_paren-1);
    }
    vector<string> generateParenthesis(int n) {
        if(n==0)
            return vector<string>();
        helper("", n, 0);
        return res;
    }
};


int main() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    for(string element: res)
        cout << element << " ";
    cout << endl;
}