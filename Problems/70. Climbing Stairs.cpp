#include "leetcode.h"


// use dynamic programming
// n == 1 => 1
// n == 2 => 2
// n == 3 => climb to n-2 and use (n==2) + climb to n-1 and use (n==1)
// 
// combination perspective in math :
// the number of ways to get to n - 1 stairs * the number of ways to get to n stair from n - 1 stairs (=1)
// the number of ways to get to n - 2 stairs * the number of ways to get to n stair from n - 2 stairs (=1)
// original the number of ways to get to n stair from n - 2 stairs should be 2
// but 1 is covered by the number of ways to get to n stair from n - 1 stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        int* steps = new int[n+1];
        steps[1] = 1;
        steps[2] = 2;
        
        for(int i=3; i<n+1; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n];
    }
};

int main() {
    int n = 5;
    Solution s;
    cout << s.climbStairs(n) << endl;
    return 0;
}