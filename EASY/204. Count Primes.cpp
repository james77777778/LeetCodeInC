#include "leetcode.h"

class Solution {
public:
    int countPrimes(int n) {
        bool primes[n+1];
        memset(primes, true, sizeof(primes));
        // find all primes
        for(int i=2; i <= sqrt(n); i++) {
            if(primes[i] == true) {
                for(int j=i*i; j<=n; j+=i)
                    primes[j] = false;
            }
        }
        int count = 0;
        for(int i=2; i<n; i++) {
            if(primes[i] == true)
                count ++;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(10) << endl;
    cout << s.countPrimes(100) << endl;
}