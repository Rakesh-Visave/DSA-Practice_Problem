#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root)
{
    int data;
    cout<<"Enter Element: "<<endl;
    cin>>data;

    root = new node(data);

    if(data == -1)
        return NULL;
    
    cout<<"Enter the Data in left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the Data in right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    node* root = NULL;

    root = buildTree(root);
}