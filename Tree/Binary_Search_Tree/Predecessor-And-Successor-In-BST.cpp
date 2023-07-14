#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };


pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int succ = -1;

    // find node(key)
    while(temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // find pred maximumm element from left sub tree
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree !=NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // find succ manimum element from right sub treee
    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    
    pair<int,int> ans = make_pair(pred,succ);
    return ans;

}


int main() {
    // Create the binary search tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(4);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(6);
    root->left->left = new BinaryTreeNode<int>(1);
    root->left->right = new BinaryTreeNode<int>(3);
    root->right->left = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(7);

    int key = 4;  // Key to find predecessor and successor for

    // Find the predecessor and successor
    pair<int, int> result = predecessorSuccessor(root, key);

    // Print the predecessor and successor
    cout << "Predecessor: " << result.first << endl;
    cout << "Successor: " << result.second << endl;

    // Delete the binary tree
    delete root;

    return 0;
}
