
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* solve(Node* root, int &k, int node)
{
     // base case
    if(root == NULL)
        return NULL;
    if(root->data == node)
        return root;
        
    Node* leftAns = solve(root->left,k,node);
    Node* rightAns = solve(root->right,k,node);
    
    // node is found if k == 0 return root else return leftAns node
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    //  node is found if k == 0 return root else return leftAns node   
    if(rightAns != NULL && leftAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;   
    
    
}
int kthAncestor(Node *root, int k, int node)
{
   Node* ans = solve(root,k,node);
//    here if the given node is at root position so it has no ancestor  if ans->data == node return -1
   if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;

    
}
int main()
{
    // Creating the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int k = 2; // Find the 2nd ancestor
    int node = 5; // Ancestor of node 5

    int ancestor = kthAncestor(root, k, node);

    if (ancestor == -1)
        cout << "No kth ancestor found for node " << node << endl;
    else
        cout << "The " << k << "th ancestor of node " << node << " is: " << ancestor << endl;

    return 0;
}
