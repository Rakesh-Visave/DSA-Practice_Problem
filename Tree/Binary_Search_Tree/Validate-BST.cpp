#include <bits/stdc++.h> 

    template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

bool isBST(BinaryTreeNode<int>* root,int min, int max)
{
    if(root == NULL)
        return true;
    
    if(root->data > min && root->data < max)
    {
        bool left = isBST(root->left , min,root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    return isBST(root,INT_MIN,INT_MAX);
}

int main() {
    // Creating a binary tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(4);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(6);
    root->left->left = new BinaryTreeNode<int>(1);
    root->left->right = new BinaryTreeNode<int>(3);
    root->right->left = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(7);

    // Validating whether the binary tree is a BST
    if (validateBST(root)) {
        std::cout << "The binary tree is a valid BST." << std::endl;
    } else {
        std::cout << "The binary tree is not a valid BST." << std::endl;
    }

    // Deleting the binary tree
    delete root;

    return 0;
}
