Problem Link: https://www.codingninjas.com/studio/problems/maximum-path-sum-between-two-leaves_8230713?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long solver(TreeNode<int>* root, long long& ans) {
    if (root == NULL) return -1e9;
    if (root->left == NULL && root->right == NULL) return root->val;

    long long left = solver(root->left, ans);
    long long right = solver(root->right, ans);
    
    if (left == -1e9 || right == -1e9) return max(left, right) + root->val;
    ans = max(ans, left+right+root->val);

    return max(left, right) + root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // if (root->left == NULL || root->right == NULL)  return -1;
    long long ans = -1;
    solver(root, ans);
    return ans;
}
