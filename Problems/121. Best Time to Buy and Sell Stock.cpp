#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = INT_MAX;
        for(int p: prices) {
            min_price = min(min_price, p);
            max_profit = max(max_profit, p-min_price);
        }
        return max_profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};  // 5
    Solution s;
    cout << s.maxProfit(prices) << endl;
}