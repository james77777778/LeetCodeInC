/******************************
//Recursive version
//Date  : 2017/10/18
//Author: JamesChiou james77777778@gmail.com
******************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL&&t2!=NULL)
        {
            TreeNode* root = new TreeNode(t2->val);
            root->left = mergeTrees(NULL,t2->left);
            root->right = mergeTrees(NULL,t2->right);
            return root;
        }
        else if(t2==NULL&&t1!=NULL)
        {
            TreeNode* root = new TreeNode(t1->val);
            root->left = mergeTrees(t1->left,NULL);
            root->right = mergeTrees(t1->right,NULL);
            return root;
        }
        else if(t1==NULL&&t2==NULL)
            return NULL;
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left,t2->left);
        root->right = mergeTrees(t1->right,t2->right);
        
        return root;
    }
};
