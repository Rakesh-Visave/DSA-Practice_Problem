#include <bits/stdc++.h> 
#include<iostream>
using namespace std;


class Node 
    {
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
int solve(Node* root, int k,int &i)
{
    if(root == NULL)
        return -1;

    int left = solve(root->left, k,i);
    if(left != -1)
        return left;
    
    i++;
    if(i == k)
        return root->data;
    
    return solve(root->right, k,i);
}
int kthSmallest(Node* root, int k) {
    int i = 0;
    int ans = solve(root,k,i);
    return ans;
}

int main() {
    // Create a binary tree
    Node* root = new Node(4);
    root->left =  new Node(2);
    root->right =  new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int k = 3;
    int kthSmallestElement = kthSmallest(root, k);

    cout << "The " << k << "th smallest element in the binary tree is: " << kthSmallestElement << endl;

    // Clean up memory
    // TODO: Implement a function to delete the binary tree nodes and free the memory

    return 0;
}
