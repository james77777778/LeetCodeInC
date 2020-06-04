#include "leetcode.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for(int c: s)
            a[c-'a']++;
        for(int c: t)
            a[c-'a']--;
        for(int i: a)
            if(i!=0)
                return false;
        return true;   
    }

    bool isAnagram_unicode(string s, string t) {
        unordered_map<int, int> char_table;
        for(int c: s)
            char_table[c]++;
        for(int c: t)
            char_table[c]--;
        for(std::pair<int, int> element: char_table)
            if(element.second!=0)
                return false;
        return true;   
    }
};


int main() {
    string a = "anagram";
    string b = "naagram";
    Solution s;
    cout << s.isAnagram(a, b) << endl;

    string a_ = "abcdefg嗨";
    string b_ = "嗨abcdefg";
    cout << int(a_[7]) << " "  << int(b_[0]) << endl;
    cout << s.isAnagram_unicode(a_, b_) << endl;
}