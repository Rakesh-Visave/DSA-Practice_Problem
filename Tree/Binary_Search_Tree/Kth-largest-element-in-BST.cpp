
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

    int kthLargest(Node *root, int &K)
    {
        if(root == NULL)
            return -1;
        
        int right = kthLargest(root->right,K);
        if(right != -1)
            return right;
        
        K--;
        if(K== 0)
            return root->data;
        
        
        return kthLargest(root->left,K);
        
    }

int main() {
    // Creating the tree
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int K = 3; // Find the 3rd largest element

    int result = kthLargest(root, K);

    if (result != -1) {
        cout << "The " << K << "th largest element is: " << result << endl;
    } else {
        cout << "Invalid input for K." << endl;
    }

    // Clean up the dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
