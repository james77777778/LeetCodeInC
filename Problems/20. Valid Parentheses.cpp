#include "leetcode.h"


class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
                par.push(c);
            else {
                if (par.empty())
                    return false;
                if (c == ')' && par.top() != '(')
                    return false;
                if (c == ']' && par.top() != '[')
                    return false;
                if (c == '}' && par.top() != '{')
                    return false;
                par.pop();
            }
        }
        return par.empty();
    }
};

int main() {
    string par = "[]{}()";
    Solution s;
    cout << s.isValid(par) << endl;
    return 0;
}