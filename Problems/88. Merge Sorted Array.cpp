#include "leetcode.h"


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1;
        int i_n1 = m-1;
        int i_n2 = n-1;
        while(i_n1 >= 0 && i_n2 >= 0) {
            if(nums2[i_n2] > nums1[i_n1]) {
                nums1[i] = nums2[i_n2];
                i--;
                i_n2--;
            }
            else {
                nums1[i] = nums1[i_n1];
                i--;
                i_n1--;
            }
        }
        while(i_n2>=0) {
            nums1[i] = nums2[i_n2];
            i--;
            i_n2--;
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    Solution s;
    s.merge(nums1, m, nums2, n);

    for(int i=0; i<nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
}