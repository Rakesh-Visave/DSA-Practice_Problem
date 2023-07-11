// GFG --Top View of Binary Tree

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


    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        // here map consist map<HD,root->data>
        map<int,int> topNode;

        // queue consist node and HD
        queue<pair<Node* , int> > q;
        
        // start form root element and here node is root and HD is 0
        q.push(make_pair(root , 0));
        
        while(!q.empty())
        {
         
         pair<Node* , int> temp = q.front();
         q.pop();
         Node* frontNode = temp.first;
         int HD = temp.second;
         
        // if the node is already that HD then update the not here we are update the vlaue
            topNode[HD] = frontNode->data;
        
        // traverse left and right
        if(frontNode->left)
            q.push(make_pair(frontNode->left , HD-1));
            
        if(frontNode->right)
            q.push(make_pair(frontNode->right , HD+1));
        }
    
    for(auto i:topNode)
    {
        ans.push_back(i.second);
    }
    
    return ans;
    
    }
    
int main() {
    // Create the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    // Find the top view
    vector<int> result = topView(root);

    // Print the top view
    cout << "Top View: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

