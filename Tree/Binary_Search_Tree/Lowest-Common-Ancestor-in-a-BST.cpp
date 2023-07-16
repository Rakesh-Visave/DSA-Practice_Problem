// GFG --- Lowest Common Ancestor in a BST
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

        Node* LCA(Node *root, int n1, int n2)
        {
            
            if(root == NULL)
                return NULL;
                

            if(root->data < n1 && root->data <n2)
                return LCA(root->right, n1,n2);
                
            if(root->data > n1 && root->data > n2)
                return LCA(root->left, n1,n2);
            
            return root;
                
            
        }


int main() {
    // Creating a binary search tree
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int n1 = 2;
    int n2 = 5;

    Node* lcaNode = LCA(root, n1, n2);
    if (lcaNode != NULL) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is " << lcaNode->data << endl;
    } else {
        cout << "Lowest Common Ancestor does not exist for " << n1 << " and " << n2 << endl;
    }

    return 0;
}
