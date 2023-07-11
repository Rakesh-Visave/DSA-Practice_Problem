// GFG -- LEETCODE -- 236. Lowest Common Ancestor of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};



    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL)
        return NULL;
        
        if(root->data == n1 || root->data == n2)
            return root;
            
        Node* leftAns = lca(root->left,n1,n2);
        Node* rightAns = lca(root->right, n1,n2);
            
        if(leftAns == NULL && rightAns ==NULL)
            return NULL;
        
         if(leftAns != NULL && rightAns ==NULL)
            return leftAns;
        
         if(leftAns == NULL && rightAns !=NULL)
            return rightAns;
        
         if(leftAns != NULL && rightAns !=NULL)
            return root;
    }

    int main()
{
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int n1 = 4;
    int n2 = 5;

    // Find the LCA of n1 and n2
    Node* lcaNode = lca(root, n1, n2);

    if (lcaNode != NULL)
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lcaNode->data << endl;
    else
        cout << "Nodes " << n1 << " and " << n2 << " are not present in the binary tree." << endl;

    return 0;
}



