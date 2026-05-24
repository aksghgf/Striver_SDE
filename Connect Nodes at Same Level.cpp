Problem Link: https://www.codingninjas.com/codestudio/problems/connect-nodes-at-same-level_8230790?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while (!q.empty()) {
        // auto node = q.front();
        int sz = q.size();
        // q.pop();

        while (sz--){
            auto node = q.front();
            // int sz = q.size();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            if (sz != 0) node->next = q.front();
        }
    }
}
