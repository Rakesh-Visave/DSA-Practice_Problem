// GFG -- Sum Tree

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

pair<bool,int> isSumTreeFast(Node* root)
{
    if(root == NULL)
    {
        pair<bool , int> p = make_pair(true,0);
        return p;
    }
    // if the node is leaf node 
    if(root->left == NULL && root->right == NULL)
    {
        pair<bool , int> p = make_pair(true,root->data);
        return p;
    }
        
    pair<bool,int> leftans = isSumTreeFast(root->left);
    pair<bool,int> rightans = isSumTreeFast(root->right);
        
    // check isSumTree
    bool left = leftans.first;
    bool right = rightans.first;
    bool cond = root->data ==leftans.second + rightans.second;
        
    pair<bool,int> ans;
    if(left && right && cond)
    {
        ans.first = true;
        // ans = left+right
        ans.second = root->data + leftans.second + rightans.second;
    }
    else
        ans.first = false;
    
    return ans;  
}
    
bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;   
}


int main() {
    // Create the sum tree
    Node* root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    bool isTreeSumTree = isSumTree(root);
    cout << "Is the tree a sum tree? " << (isTreeSumTree ? "true" : "false") << endl;

    // Clean up the allocated memory (optional)
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}




