#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* cur, long min_v, long max_v) {
        if(cur == nullptr)
            return true;
        if(cur->val <= min_v || cur->val >= max_v)
            return false;
        return helper(cur->left, min_v, cur->val)
               && helper(cur->right, cur->val, max_v);
    }
};


int main() {
    
}