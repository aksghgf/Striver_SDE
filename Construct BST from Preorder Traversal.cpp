Problem Link: https://www.codingninjas.com/studio/problems/construct-bst-from-preorder-traversal_8230850?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* insert(TreeNode<int>* root, int d) {
    if (root == NULL) {
        return new TreeNode<int>(d);
    }

    if (d<root->data) root->left = insert(root->left, d);
    else root->right = insert(root->right, d);

    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    TreeNode<int>* root = new TreeNode<int>(preOrder[0]);
    for (int i=1; i<preOrder.size(); i++) {
        insert(root, preOrder[i]);
    }

    return root;
}
