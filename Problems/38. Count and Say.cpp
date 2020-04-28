#include "leetcode.h"


class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)
            return "";
        else if(n == 1)
            return "1";
        
        string ans = "1";
        string temp = "";
        for(int i=2; i<n+1; i++) {
            for(int j=0; j<ans.length(); j++) {
                int count = 1;
                while((ans[j] == ans[j+1]) && (j+1<ans.length())) {
                    count++;
                    j++;
                }
                temp += std::to_string(count) + ans[j];
            }
            ans = temp;
            temp = "";
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(5) << endl;  // 111221
    return 0;
}