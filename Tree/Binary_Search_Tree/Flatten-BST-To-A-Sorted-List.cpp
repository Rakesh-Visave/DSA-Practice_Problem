#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

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

void storeInorder(TreeNode<int>* root , vector<int> &in)
{
    if(root == NULL)
        return;
    
    storeInorder(root->left ,in);

    in.push_back(root->data);

    storeInorder(root->right,in);

 }

TreeNode<int>* flatten(TreeNode<int>* root)
{
//    step -1 find inorder in vector<int>
   vector<int> inorder;
   storeInorder(root,inorder);

   int n = inorder.size();

//    step-2 creat a first node 
   TreeNode<int>* first = new TreeNode<int>(inorder[0]);
   TreeNode<int>* curr = first;

// step-3 curr->left = next element 
   for(int i = 1; i<n; i++)
   {
    TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
    curr->left = NULL;
    curr->right = temp;
    curr = temp;
   }
// step-4 curr now at last position so curr->left = NULL && curr->right = NULL
   curr->left = NULL;
   curr->right = NULL;

   return first;
}


int main()
{
    // Create a sample tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);

    // Flatten the tree
    TreeNode<int>* flattened = flatten(root);

    // Print the flattened tree
    TreeNode<int>* curr = flattened;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;

    // Clean up the memory
    delete flattened;

    return 0;
}