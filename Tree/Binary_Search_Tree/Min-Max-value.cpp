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


Node* maxElement(Node* root)
{
    Node* temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
Node* minElement(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
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

    cout<<"Minimum Element in BST is: "<<minElement(root)->data<<endl;
    cout<<"Maximum Element in BST is: "<<maxElement(root)->data<<endl;

}
