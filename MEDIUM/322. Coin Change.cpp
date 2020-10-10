#include "leetcode.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // construct dp array (index means the amount)
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        // sort coins for convenience
        sort(coins.begin(), coins.end());
        for(int i=1; i<amount+1; i++) {
            for(int c: coins) {
                // i-c < 0 means no suitable coin to get i (value)
                if(i-c < 0)
                    break;
                // dp[i-c] != INT_MAX means there has a previous coin solution
                if(dp[i-c] != INT_MAX) {
                    // we need min() since there is for(int c: coins) loop
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        if(dp[amount] != INT_MAX)
            return dp[amount];
        else
            return -1;
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution sol;
    cout << sol.coinChange(coins, amount) << endl;
}