#include "leetcode.h"


// [0, 1, 2, 3, 4, 5, 6, 7, 8], k=3
// 0->3, 1->4, 2->5, 3->6, 4->7, 5->8, 6->0, 7->1, 8->2
// do the independent sets: 0->3, 3->6, 6->0 (finished the sets: encounter start point)
// do next independent sets: 1->4, 4->7, 7->1 (finished the sets: encounter start point)
// every independent sets is shift by 1, so add 1 is reasonable


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
            return;
        k %= nums.size();
        int i=0;
        int temp1 = nums[0], temp2;
        int next_idx = 0;
        for(int j=0; j<nums.size(); j++) {
            next_idx = (next_idx+k) % nums.size();
            
            temp2 = nums[next_idx];
            nums[next_idx] = temp1;
            temp1 = temp2;
            
            if(next_idx == i) {
                next_idx = ++i;
                if(next_idx > nums.size()-1)
                    return;
                temp1 = nums[next_idx];
            }
        }
    }
};