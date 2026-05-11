Problem Link: https://www.codingninjas.com/codestudio/problems/symmetric-tree_8230686?challengeSlug=striver-sde-challenge&leftPanelTab=0

/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool identicalTrees(BinaryTreeNode<int>* r1, BinaryTreeNode<int>* r2) {
    if (r1 == NULL && r2 != NULL) return false;
    if (r1 != NULL && r2 == NULL) return false;
    if (r1 == NULL && r2 == NULL) return true; 

    if (r1->data != r2->data) return false;
    bool left = identicalTrees(r1->left, r2->right);
    bool right = identicalTrees(r1->right, r2->left);
    return left&&right;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if (root == NULL) return true;
    return identicalTrees(root->left, root->right);   
}
