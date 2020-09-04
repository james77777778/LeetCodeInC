#include "leetcode.h"

class Solution {
public:
    string countingSort(string t) {
        vector<int> count(26);
        for(int i=0; i<t.size(); i++) {
            count[t[i]-'a']++;
        }
        string r;
        for(int j=0; j<26; j++) {
            r += string(count[j], j+'a');  // string(size_t, char);
        }
        return r;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(string& s: strs) {
            string tmp = s;
            // tmp = countingSort(tmp);
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s);  
        }
        for(auto& ss: m) {
            res.push_back(ss.second);
        }
        return res;
    }
};


int main() {
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    Solution sol;
    vector<vector<string>> res = sol.groupAnagrams(strs);
    for(vector<string>& item: res) {
        for(string& s: item) {
            cout << s << " ";
        }
        cout << endl;
    }
}