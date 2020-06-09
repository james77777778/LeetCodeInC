#include "leetcode.h"

class Solution {
public:
    const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return vector<string>();
        res.push_back("");
        int num;
        for(int i=0; i<digits.size(); i++) {
            num = digits[i] - '0';
            if(num<1 || num>9)
                break;
            const string candidate = v[num];
            vector<string> temp;
            for(int j=0; j<res.size(); j++) {
                for(int k=0; k<candidate.size(); k++)
                    temp.push_back(res[j] + candidate[k]);
            }
            res.swap(temp);
        }
        return res;
    }
};


int main() {
    string digits = "234";
    Solution sol;
    vector<string> res = sol.letterCombinations(digits);
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}