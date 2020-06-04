#include "leetcode.h"

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i=1; i<=n; i++)
            res[i-1] = std::to_string(i);
        for(int i=3-1; i<n; i+=3)
            res[i] = "Fizz";
        for(int i=5-1; i<n; i+=5)
            res[i] = "Buzz";
        for(int i=15-1; i<n; i+=15)
            res[i] = "FizzBuzz";
        return res;
    }
};


int main() {
    int n = 15;
    Solution sol;
    vector<string> s = sol.fizzBuzz(n);
    for(string i: s)
        cout << i << " ";
    cout << endl;
}