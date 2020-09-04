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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return vector<vector<int>>();
        helper(root, 0);
        return res;
    }
    void helper(TreeNode* cur, int level) {
        if(cur == nullptr)
            return;
        if(res.size()<=level)
            res.push_back({cur->val});
        else {
            res[level].push_back(cur->val);
        }
        helper(cur->left, level+1);
        helper(cur->right, level+1);
    }
};


int main() {
    
}