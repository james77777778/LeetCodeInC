#include "leetcode.h"

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur(root);
        stack<TreeNode*> s;
        while(cur!=nullptr || !s.empty()) {
            while(cur!=nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        TreeNode* cur(root);
        helper(cur);
        return res;
    }
    void helper(TreeNode* cur) {
        if(cur == nullptr)
            return;
        helper(cur->left);
        res.push_back(cur->val);
        helper(cur->right);
    }
};

int main() {
    
}