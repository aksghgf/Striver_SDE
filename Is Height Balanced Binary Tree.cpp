Problem Link: https://www.codingninjas.com/codestudio/problems/is-height-balanced-binary-tree_8230771?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
pair<int, bool> solver(BinaryTreeNode<int>* root) {
    if (root == NULL) return {0, true};

    auto left = solver(root->left);
    auto right = solver(root->right);
    int height = max(left.first, right.first) + 1;

    if (abs(left.first - right.first) > 1) return {height, false};
    
    return {height, (left.second && right.second)};
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    auto it = solver(root);
    return it.second;
}
