Problem Link: https://www.codingninjas.com/codestudio/problems/tree-traversals_8230775?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
https://www.codingninjas.com/codestudio/problems/tree-traversals_8230775?challengeSlug=striver-sde-challenge&leftPanelTab=0
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void solver(BinaryTreeNode<int>* root, vector<vector<int>>& traversals) {
    if (root == NULL) return;

    stack<pair<BinaryTreeNode<int>*, int>> st;
    st.push({root, 0});
    vector<int> preOrder, inOrder, postOrder;
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        int visit = it.second;
        BinaryTreeNode<int>* node = it.first;

        // if we are visiting the node for the first time means it is preOrder traversal and 
        // we have to keep going left
        if (visit == 0) {
            preOrder.push_back(node->data);
            st.push({node, visit+1});
            if (node->left != NULL) {
                st.push({node->left, 0});
            }
        }
        // this means we are visiting the node for the secind time
        // and it is inorder and we have to go right
        if (visit == 1) {
            inOrder.push_back(node->data);
            st.push({node, visit+1});
            if (node->right != NULL) {
                st.push({node->right, 0});
            }
        }

        // this means that we are visit the node for the last time 
        // and it is post order traversal
        if (visit == 2) {
            postOrder.push_back(node->data);
        }
    } 
    traversals.push_back(inOrder);
    traversals.push_back(preOrder);
    traversals.push_back(postOrder);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> traversals;
    solver(root, traversals);
    return traversals;
}
