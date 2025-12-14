Problem Link: https://www.codingninjas.com/codestudio/problems/maximum-width-in-binary-tree_8230710?challengeSlug=striver-sde-challenge&leftPanelTab=0

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

int getMaxWidth(TreeNode<int> *root)
{
    if (root == NULL) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int width = 1;

    while (!q.empty()) {
        int currWidth = q.size();
        width = max(width, currWidth);

        while (currWidth--) {
            auto it = q.front();
            q.pop();
            if (it->left) q.push(it->left);
            if (it->right) q.push(it->right);
        }
    }
    return width;
}
