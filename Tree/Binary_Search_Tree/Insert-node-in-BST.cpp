//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


        Node* insert(Node* node, int data) {
        
            if(node == NULL)
            {
                node =  new Node(data);
                return node;
            }
            
            if(node->data == data)
                return node;
            
            if(data > node->data)
                node->right = insert(node->right,data);
            
            else
                node->left = insert(node->left, data);
            
            
            return node;
    }

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}


int main() {
    // Hardcoded input
    vector<int> values = {82, 1, 106, 58, 89, 56, 68, 92, 24, 35, 26};

    // Create the root node
    Node* root = new Node(values[0]);

    // Insert the rest of the values
    for (size_t i = 1; i < values.size(); ++i) {
        insert(root, values[i]);
    }

    // Perform inorder traversal to get the sorted elements
    vector<int> sortedValues;
    inorder(root, sortedValues);

    // Print the sorted elements
    for (int val : sortedValues) {
        cout << val << " ";
    }

    return 0;
}
