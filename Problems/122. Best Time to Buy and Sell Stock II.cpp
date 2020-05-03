#include "leetcode.h"


// Use monotone increase property.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1; i<prices.size(); i++)
            profit += prices[i] > prices[i-1] ? prices[i] - prices[i-1] : 0;
        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1 ,5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
}