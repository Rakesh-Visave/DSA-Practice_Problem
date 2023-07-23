// GFG -- Right View of Binary Tree


#include <bits/stdc++.h>
using namespace std;

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

    void solve(Node* root , vector<int> &ans, int level)
    {
        if(root == NULL)
            return;
        
        if(level == ans.size())
        {
            ans.push_back(root->data);
        }
        
        solve(root->right,ans,level+1);
        solve(root->left, ans,level+1);
    }
    
    vector<int> rightView(Node *root)
    {
      vector<int> ans;
      solve(root , ans, 0);
      return ans;
    }


int main()
{
    // Create the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);
    root->right->left->right = newNode(8);

    // Get the right view of the binary tree
    vector<int> result = rightView(root);

    // Print the right view elements
    cout << "Right View: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}