#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node( int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* root , int data)
{
    if(root == NULL)
    {
        root = new Node(data);
            return root;
    }
    if(data > root->data)
        root->right = insertToBST(root->right, data);
    else
        root->left = insertToBST(root->left, data);
    
    return root;
}
void takeInput(Node* root)
{
    int data;
    cin>>data;

    if(data != -1)
    {
        root = insertToBST(root, data);
        cin>>data;
    }
}


int main()
{
    Node * root = NULL;
    cout<<"Enter the data for creating BST: ";
    takeInput(root);

    return 0;
}