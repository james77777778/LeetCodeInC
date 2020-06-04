#include "leetcode.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for(int i=0, j=s.size()-1; i<j; i++, j--) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};


int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);
    for(char c: s)
        cout << c << " ";
    cout << endl;
}