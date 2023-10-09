

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
        



    int height(struct Node* node){
         if(!node)
            return 0;
        
        return max(height(node->left), height(node->right)) + 1;
    }

int main() {
    // Creating nodes
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calculating height
    int treeHeight = height(root);

    // Printing the height
    cout << "Height of the tree is: " << treeHeight << endl;

    // Freeing allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
