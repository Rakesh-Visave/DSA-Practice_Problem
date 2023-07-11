// CODESTUDIO -- Count Leaf Nodes

#include<iostream>
using namespace std;

    template <typename T>
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
    };
    

void inorder(BinaryTreeNode<int> *root, int &count)
{
    if(root == NULL)
        return ;

    inorder(root->left,count);
    if(root->left == NULL && root->right == NULL)
        count++;
    
    inorder(root->right,count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    
    int cnt = 0;
    inorder(root,cnt);
    return cnt;
}

int main() {
    // Create the binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    // Count the number of leaf nodes
    int leafCount = noOfLeafNodes(root);

    // Print the result
    cout << "Number of leaf nodes: " << leafCount << endl;


    return 0;
}
