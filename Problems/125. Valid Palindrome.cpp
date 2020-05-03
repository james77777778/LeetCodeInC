#include "leetcode.h"


// Use isalnum to check whether the char is a valid alphanumeric


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
            return true;
        int i = 0, j = s.size()-1;
        while(i<j) {
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else {
                if(tolower(s[i++]) != tolower(s[j--]))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    string st = "A man, a plan, a canal: Panama";
    Solution s;
    cout << s.isPalindrome(st) << endl;
}