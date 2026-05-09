Problem Link: https://www.codingninjas.com/studio/problems/bst-iterator_8230815?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

class BSTiterator
{
    public:
    stack<TreeNode<int>*> st;

    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int>* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushAll(TreeNode<int>* node) {
        for (; node!= NULL; st.push(node), node=node->left) {

        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
