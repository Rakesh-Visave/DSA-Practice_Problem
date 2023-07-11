// GFG -- Boundary-Traversal-of-binary-tree

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000


struct Node
{
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

    // traverse left nodes stop when leaf node occurs 
    void traversalLeft(Node* root , vector<int> &ans)
    {
        // checking leaf node
        if(root == NULL || root->left == NULL && root->right == NULL)
            return;

        // here node is not a leaf not stores the node   
        ans.push_back(root->data);
        // left node exists
        if(root->left)
            traversalLeft(root->left,ans);
        else
            traversalLeft(root->right,ans);
            
    }
    
    // traverse leaf nodes
    void traverseLeaf(Node* root , vector<int> &ans)
    {
        if(root == NULL)
            return;
        // checking leaf node if yes then store ans   
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    
    // traverse right part ans gives a right node when recursion returns
    void traverseRight(Node* root , vector<int> &ans)
    {
        // checking leaf node
        if(root == NULL || root->left == NULL && root->right == NULL)
            return;
            
        // check right part exists
        if(root->right)
            traverseRight(root->right,ans);
        else
            traverseRight(root->left,ans);
            
        // when returns store node in ans
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        // step-1 storing a left part data
        traversalLeft(root->left,ans);
        
        // step-2 for storing leaf Nodes
            // for left  subtree
            traverseLeaf(root->left, ans);
            
            // for right subtree
            traverseLeaf(root->right, ans);
            
        // step-3 sotring right part of data
        traverseRight(root->right,ans);
        
        return ans;
            
            
    }

int main() {
    // Create the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Perform boundary traversal
    vector<int> result = boundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
