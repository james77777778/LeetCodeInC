#include "leetcode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area = 0;
        while(left < right) {
            max_area = max(max_area, (right-left)*min(height[left], height[right]));
            if(height[left] < height[right])
                left ++;
            else
                right --;
        }
        return max_area;
    }
};


int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout << sol.maxArea(height) << endl;
}