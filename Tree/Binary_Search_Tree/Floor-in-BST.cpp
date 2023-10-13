// GFG -- Floor in BST


#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};



    int floor(Node* root, int x) {
         int floorValue = -1;

        while (root != NULL)
        {
            if (root->data == x)
            {
                return x;
            } 
            else if (root->data < x)
            {
                floorValue = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        return floorValue;
    }


//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


int main() {
    // Creating the BST
    Node *root = NULL;
    root = insert(root, 15);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 10);
    insert(root, 18);
    insert(root, 25);

    // Hardcoded value to find the floor for
    int x = 17;

    // Finding the floor value
    int result = floor(root, x);

    // Printing the result
    if (result != -1) {
        cout << "Floor value of " << x << " is: " << result << endl;
    } else {
        cout << "No floor value found for " << x << endl;
    }

    return 0;
}


