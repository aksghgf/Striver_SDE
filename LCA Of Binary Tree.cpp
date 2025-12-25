Problem Link: https://www.codingninjas.com/codestudio/problems/lca-of-binary-tree_8230760?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int helper(TreeNode<int>* root, int x, int y) {
    if (root == NULL) return -1;

    if (root->data == x || root->data == y) return root->data;

    int leftData = helper(root->left, x, y);
    int rightData = helper(root->right, x, y);

    if (leftData != -1 && rightData != -1) return root->data;
    else if (leftData != -1) return leftData;
    else if (rightData != -1) return rightData;
    return -1;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return helper(root, x, y);
}
