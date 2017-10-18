/******************************
//Recursive version
//Date  : 2017/10/17
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recursiveMBT(nums,0,nums.size());
    }
    //
    // Returns root node of Maximum Binary Tree. 
	// Input the address of vector of numbers , left index and right index.
	//
    TreeNode* recursiveMBT(vector<int>& nums,int l,int r) {
        //If left and right index collide means the end of recursion
		if(l==r)
            return NULL;
        //Find the maximum index to be the root
        int maxI = findMaxI(nums,l,r);
        TreeNode* root = new TreeNode(nums[maxI]);
        //Recursion of left
        root->left = recursiveMBT(nums,l,maxI);
        //Recursion of right
        root->right = recursiveMBT(nums,maxI+1,r);
        
        return root;
    }
    //
    // Returns maximum index of the vector of numbers. 
	// Input the address of vector of numbers , left index and right index.
	//
    int findMaxI(vector<int>& nums,int l,int r) {
        int maxI = l;
        for(int i=l;i<r;i++)
            if(nums[i]>nums[maxI])
                maxI = i;
        return maxI;
    }
};
