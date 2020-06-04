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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* left, TreeNode* right) {
        if(!left && !right)
            return true;
        else if(!left || !right)
            return false;
        if(left->val != right->val)
            return false;
        return helper(left->left, right->right) & helper(left->right, right->left);
    }
};

int main() {
    TreeNode left = TreeNode(10);
    TreeNode right = TreeNode(10);
    TreeNode root = TreeNode(5, &left, &right);
    Solution s;
    cout << s.isSymmetric(&root) << endl;
}