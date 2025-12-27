Problem Link: https://www.codingninjas.com/codestudio/problems/floor-in-bst_8230753?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    TreeNode<int>* temp = root;
    while (temp) {
        if (temp->val == X) return temp->val;
        if (X<temp->val) temp = temp->left;
        else {
            floor = temp->val;
            temp = temp->right;
        }
    }
    return floor;
}
