#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

    class Node {
    public : 
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


bool searchInBST(Node* root, int x) {
    
    Node *temp = root;
    while(temp != NULL)
    {
        if(temp->data  == x)
            return true;
        if(temp->data > x)
        {
            temp = temp->left;
        }
        else
            temp  = temp->right;
    }
    return false;
    
}

int main() {
    // Create a sample binary search tree
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Search for a value in the binary search tree
    int searchValue = 5;
    bool isFound = searchInBST(root, searchValue);

    if (isFound) {
        cout<< "Value " << searchValue << " is found in the binary search tree." << endl;
    } else {
        cout<< "Value " << searchValue << " is not found in the binary search tree." << endl;
    }

    return 0;
}