#include "leetcode.h"


// use t = t & (t-1) to continously drop the least 1 bit
// ex: 00010110
// 00010110 & 00010101 = 00010100
// 00010100 & 00010011 = 00010000
// 00010000 & 00001111 = 00000000
// count = 3


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t t = n;
        while(t) {
            t = t & (t-1);
            count ++;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight((int) 0b00010110) << endl;
}