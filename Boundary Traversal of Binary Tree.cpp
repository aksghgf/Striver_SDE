Problem Link: https://www.codingninjas.com/codestudio/problems/boundary-traversal-of-binary-tree_8230712?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void getLeft(TreeNode<int>* root, vector<int>& ans) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) return;
    ans.push_back(root->data);
    if (root->left) {
        getLeft(root->left, ans);
    }else getLeft(root->right, ans);
}

void getLeaves(TreeNode<int>* root, vector<int>& ans){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    getLeaves(root->left, ans);
    getLeaves(root->right, ans);
}

void getRight(TreeNode<int>* root, vector<int>& ans) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) return;
    if (root->right) {
        getRight(root->right, ans);
    }else getRight(root->left, ans);
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){

    vector<int> ans;
    if (root == NULL) return ans;
    ans.push_back(root->data);
    getLeft(root->left, ans);
    getLeaves(root->left, ans);
    getLeaves(root->right, ans);
    getRight(root->right, ans);
    return ans;
}
