#include "leetcode.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        if(nums.size() == 1)
            return new TreeNode(nums[0]);
        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> left_nums(nums.begin(), nums.begin()+mid);
        vector<int> right_nums(nums.begin()+mid+1, nums.end());
        
        root->left = sortedArrayToBST(left_nums);
        root->right = sortedArrayToBST(right_nums);
        return root;
    }
};

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    printTree(root);
}