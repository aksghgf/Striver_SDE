Problem Link: https://www.codingninjas.com/codestudio/problems/inorder-traversal_8230857?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void solver(vector<int> &ans, TreeNode* root){
    if (root == NULL) return ;

    solver(ans, root->left);
    ans.push_back(root->data);
    solver(ans, root->right);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    solver(ans, root);
    return ans;
}
