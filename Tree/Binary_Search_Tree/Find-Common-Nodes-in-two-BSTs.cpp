// GFG -- Find Common Nodes in two BSTs


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

    vector<int> out;
    bool find(Node* node, int x){

        if(!node)
            return 0;
        
        if(node->data == x)
            return 1;
        if(node->data > x)
            return find(node->left, x);
        
        return find(node->right, x);
    }
    void inorder(Node* root1, Node* root2){
        if(!root1)
            return;
        
        inorder(root1->left, root2);
        if(find(root2, root1->data))
            out.push_back(root1->data);
        inorder(root1->right, root2);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
      inorder(root1, root2);
       return out;
    }

int main() {
    // Creating the first BST
    Node* root1 = new Node(5);
    root1->left = new Node(2);
    root1->right = new Node(8);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right->left = new Node(7);
    root1->right->right = new Node(9);

    // Creating the second BST
    Node* root2 = new Node(3);
    root2->left = new Node(1);
    root2->right = new Node(5);
    root2->left->left = new Node(0);
    root2->left->right = new Node(2);
    root2->right->left = new Node(4);
    root2->right->right = new Node(6);

    // Finding common nodes
    vector<int> commonNodes = findCommon(root1, root2);

    // Printing the common nodes
    cout << "Common nodes are: ";
    for (int i : commonNodes) {
        cout << i << " ";
    }

    // Freeing the allocated memory
    delete root1->right->right;
    delete root1->right->left;
    delete root1->right;
    delete root1->left->right;
    delete root1->left->left;
    delete root1->left;
    delete root1;

    delete root2->right->right;
    delete root2->right->left;
    delete root2->right;
    delete root2->left->right;
    delete root2->left->left;
    delete root2->left;
    delete root2;

    return 0;
}
