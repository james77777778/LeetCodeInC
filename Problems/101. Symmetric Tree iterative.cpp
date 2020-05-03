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
        queue<TreeNode*> check;
        check.push(root->left);
        check.push(root->right);
        TreeNode *p1, *p2;
        
        while(!check.empty()) {
            p1 = check.front();
            check.pop();
            p2 = check.front();
            check.pop();
            if(!p1 && !p2)
                continue;
            if(!p1 || !p2)
                return false;
            if(p1->val != p2->val)
                return false;
            if(p1 && p2) {
                check.push(p1->left);
                check.push(p2->right);
                check.push(p1->right);
                check.push(p2->left);
            }
        }
        return true;
    }
};

int main() {
    TreeNode left = TreeNode(10);
    TreeNode right = TreeNode(10);
    TreeNode root = TreeNode(5, &left, &right);
    Solution s;
    cout << s.isSymmetric(&root) << endl;
}