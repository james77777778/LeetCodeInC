#include "leetcode.h"

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int right = 0;
        int res = 0;
        for(int i=0; i < light.size(); i++) {
            right = max(right, light[i]);  // maintain the rightmost index
            if(right == i+1)  // if the number of turned on bulbs (i+1) is the same as rightmost index (right)
                res ++;       // then all bulbs will turn into blue
        }
        return res;
    }
};


int main() {
    vector<int> light = {2, 1, 3, 5, 4};
    Solution s;
    cout << s.numTimesAllBlue(light) << endl;
}