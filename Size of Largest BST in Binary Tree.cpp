Problem Link: https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_8230743?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class BST{
    public: 
    int min;
    int max;
    int size;

    BST(int minNode, int maxNode, int maxSize) {
        this->min = minNode;
        this->max = maxNode;
        this->size = maxSize;
    }
};

BST helper(TreeNode<int>* root) {
    if (root == NULL) return BST{INT_MAX, INT_MIN, 0};

    auto leftCall = helper(root->left);
    auto rightCall = helper(root->right);

    if (root->data > leftCall.max && root->data < rightCall.min) {
        return BST(min(leftCall.min, min(root->data, rightCall.min)), max(root->data, max(root->data, rightCall.max)), 
                    leftCall.size + rightCall.size + 1);
    }

    return BST(INT_MIN, INT_MAX, max(leftCall.size, rightCall.size));
}

int largestBST(TreeNode<int>* root) 
{
    return helper(root).size;
}
